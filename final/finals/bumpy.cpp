#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> p;
    DSU(int n) {
        p.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) p[i] = i;
    }
    int find(int i) {
        if (p[i] == i) return i;
        return p[i] = find(p[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) p[root_i] = root_j;
    }
};

vector<pair<int, int>> adj[100005];
int disc[100005], low[100005], timer;
bool found_bridge = false;
int r1, rN;

void dfs_bridge(int u, int p_edge_idx) {
    disc[u] = low[u] = ++timer;
    for (auto &edge : adj[u]) {
        int v = edge.first;
        int idx = edge.second;
        if (idx == p_edge_idx) continue;
        if (disc[v]) {
            low[u] = min(low[u], disc[v]);
        } else {
            dfs_bridge(v, idx);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                // เช็คว่าสะพานนี้กั้นระหว่าง r1 และ rN หรือไม่
                // โดยการดูว่าจากกลุ่ม v สามารถไปถึง rN ได้หรือไม่ (ในขณะที่ u ไปทาง r1)
                // หรือใช้การเช็ค Component หลังตัด Edge (แต่ในที่นี้ใช้ DFS เช็คทางผ่านได้)
            }
        }
    }
}

// เพื่อความชัวร์และประสิทธิภาพ: ใช้ BFS เช็คหลังลองลบถนน w=L ทีละเส้นเฉพาะเส้นที่เป็นไปได้
// แต่เนื่องจาก N=100,000 การลบทีละเส้นจะช้าเกินไป 
// ดังนั้นเราจะใช้ Logic: ถ้าถนน w=L ทั้งหมดที่ประกอบกันเป็นทางเดินจาก r1 ไป rN มี "สะพาน" จะตอบ Y

bool visited[100005];
bool on_path[100005];
vector<int> path_edges;

bool find_any_path(int u, int target, vector<pair<int, int>> &current_path) {
    visited[u] = true;
    if (u == target) return true;
    for (auto &edge : adj[u]) {
        if (!visited[edge.first]) {
            current_path.push_back({u, edge.second});
            if (find_any_path(edge.first, target, current_path)) return true;
            current_path.pop_back();
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<Edge> all_edges(M);
    for (int i = 0; i < M; i++) cin >> all_edges[i].u >> all_edges[i].v >> all_edges[i].w;

    sort(all_edges.begin(), all_edges.end(), [](Edge a, Edge b) { return a.w < b.w; });

    DSU d_total(N);
    int L = 0;
    for (auto &e : all_edges) {
        d_total.unite(e.u, e.v);
        if (d_total.find(1) == d_total.find(N)) { L = e.w; break; }
    }
    cout << L << "\n";

    DSU d_less(N);
    for (auto &e : all_edges) if (e.w < L) d_less.unite(e.u, e.v);

    r1 = d_less.find(1);
    rN = d_less.find(N);

    if (r1 == rN) { cout << "N\n"; return 0; }

    int edge_idx = 0;
    for (auto &e : all_edges) {
        if (e.w == L) {
            int u = d_less.find(e.u), v = d_less.find(e.v);
            if (u != v) {
                adj[u].push_back({v, edge_idx});
                adj[v].push_back({u, edge_idx});
                edge_idx++;
            }
        }
    }

    // ใช้การเช็ค Edge-Connectivity: ถ้า Min-cut ระหว่าง r1 และ rN คือ 1 จะตอบ Y
    // ในกราฟที่ไม่มีค่าน้ำหนัก (หรือน้ำหนักทุกเส้นเป็น 1) Min-cut คือจำนวน Bridge ที่กั้น
    // เราจะใช้ Max flow แบบง่าย (Edmonds-Karp) หรือ DFS 2 รอบเพื่อหาเส้นทางที่ไม่ซ้ำกัน
    
    auto get_path = [&]() {
        vector<int> parent_node(N + 1, -1), parent_edge(N + 1, -1);
        vector<int> q; q.push_back(r1);
        parent_node[r1] = r1;
        int head = 0;
        while(head < q.size()){
            int u = q[head++];
            if(u == rN) break;
            for(auto &edge : adj[u]){
                if(parent_node[edge.first] == -1){
                    parent_node[edge.first] = u;
                    parent_edge[edge.first] = edge.second;
                    q.push_back(edge.first);
                }
            }
        }
        return parent_edge;
    };

    vector<int> p_edge = get_path();
    if (p_edge[rN] == -1) { cout << "N\n"; return 0; }

    // ลองลบเส้นทางที่เพิ่งพบ แล้วดูว่ายังไปได้ไหม
    int count_paths = 0;
    // เทคนิค: ถ้ามี Bridge ที่กั้นระหว่าง r1 และ rN จะตอบ Y
    // เราใช้การหา Bridge ของ Tarjan บนโหนดที่ยุบแล้ว
    
    vector<int> tin(N + 1, -1), low(N + 1, -1);
    int timer = 0;
    bool has_critical_bridge = false;

    auto dfs_b = [&](auto self, int u, int p_idx) -> void {
        tin[u] = low[u] = timer++;
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int idx = edge.second;
            if (idx == p_idx) continue;
            if (tin[v] != -1) {
                low[u] = min(low[u], tin[v]);
            } else {
                self(self, v, idx);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    // นี่คือสะพาน! เช็คว่ามันกั้น r1 กับ rN หรือไม่
                    // วิธีเช็ค: ถ้าเราอยู่ฝั่ง r1 และ v นำไปสู่ rN
                    // ในที่นี้เราจะเช็คว่า rN อยู่ใน Subtree ของ v หรือไม่
                }
            }
        }
    };

    // เพื่อความแม่นยำสูงสุด: ถ้าเราลบถนน w=L "ทุกเส้น" ที่เป็น Bridge 
    // แล้วเช็คว่ามีเส้นไหนที่กั้น r1 จาก rN 
    // หรือใช้ง่ายกว่านั้น: ลองใช้ Max Flow (Capacity ทุกเส้นเป็น 1)
    // ถ้า Max Flow จาก r1 ไป rN มีค่าเท่ากับ 1 ตอบ Y, ถ้า > 1 ตอบ N
    
    // (ใช้ Edmonds-Karp แบบสั้น)
    int flow = 0;
    vector<int> capacity(edge_idx, 1);
    while (true) {
        vector<int> parent_n(N + 1, -1), parent_e(N + 1, -1);
        vector<int> q; q.push_back(r1); parent_n[r1] = r1;
        int head = 0;
        while(head < q.size()){
            int u = q[head++];
            for(auto &e : adj[u]){
                if(parent_n[e.first] == -1 && capacity[e.second] > 0){
                    parent_n[e.first] = u;
                    parent_e[e.first] = e.second;
                    q.push_back(e.first);
                }
            }
        head++;
        }
        if(parent_n[rN] == -1) break;
        flow++;
        if(flow > 1) break;
        for(int v = rN; v != r1; v = parent_n[v]) capacity[parent_e[v]]--;
    }

    if (flow == 1) cout << "Y\n";
    else cout << "N\n";

    return 0;
}