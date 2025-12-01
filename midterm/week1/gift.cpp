#include <iostream>

using namespace std;



bool is_used[200001]; 



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    int n, k, t;

    if (!(cin >> n >> k >> t)) return 0;



    int target_index = t - 1; 

    

    int count = 0 ;

    int index = 0 ; 

    int total_steps = 0; 

    

    if (!is_used[0]) {

        is_used[0] = true;

        count++; 

    }



    if (index == target_index) {

        cout << count << "\n";

        return 0;

    }

    

    index = (index + k) % n;



    while (true) {

        

        if (index == target_index) {

            if (!is_used[index]) {

                 count++;

            }

            break; 

        }

        

        if (!is_used[index]) {

            is_used[index] = true;

            count++; 

        }



        if (index == 0 && total_steps > 0) {

            break; 

        }

        

        index = (index + k) % n;

        total_steps++;

    }



    cout << count << "\n";



    return 0;

}
