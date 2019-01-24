#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

#define MAX_ 1000010001
#define MIN_ -1000000001
using namespace std;

pair<long long, int> points[10000];
//0 <= x_, y_ <= 1000000000
pair<long long, int> num_of_horizon[3][10000];   //remain[0] = no gguk , remain[1] = down gguk, remain[2] = up gguk=> remain[i][j] = <height, number of horizon> 
// 1 <= h <= 10000
int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	scanf("%d", &T);
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;

        int num_of_points;
        scanf("%d", &num_of_points);
        for (int i = 0; i < num_of_points; i++) {
            num_of_horizon[0][i] = make_pair(0, 0);
            num_of_horizon[1][i] = make_pair(0, 0);
            long long tmp, y;
            int h;
            scanf("%lld", &tmp);
            scanf("%lld", &y);
            scanf("%d", &h);

            points[i] = make_pair(y, h);
        }
        
        sort(points, points + num_of_points);
        num_of_horizon[0][0] = make_pair(points[0].first, 1);
        num_of_horizon[1][0] = make_pair(MIN_, 0);
        num_of_horizon[2][0] = make_pair(MAX_, 0);

        for (int i = 1; i < num_of_points; i++) {
            long long min_height_h = num_of_horizon[0][i-1].first;
            int max_horizon_h = num_of_horizon[0][i-1].second;
            long long min_height_d = num_of_horizon[1][i-1].first;
            int max_horizon_d = num_of_horizon[1][i-1].second;
            long long min_height_u = num_of_horizon[2][i-1].first;
            int max_horizon_u = num_of_horizon[2][i-1].second;
            long long height;
            int horizon;

            if (min_height_h <= points[i].first) {
                if (min_height_h == MIN_) {
                    horizon = max_horizon_h + 1;
                    height = points[i].first;
                }
                else if (points[i].first - min_height_h > points[i].second) {
                    horizon = max_horizon_h + 1;
                    height = points[i].first;
                }
                else if (points[i].first - min_height_h <= points[i].second) {
                    horizon = max_horizon_h + 1;
                    height = min_height_h + points[i].second;
                }
            }
            if (min_height_d <= points[i].first) {
                if (min_height_d == MIN_) {
                    if (horizon < max_horizon_d + 1) {
                        horizon = max_horizon_d + 1;
                        height = points[i].first;
                    }
                    else if (horizon == max_horizon_d + 1 && height > points[i].first) {
                        height = points[i].first;
                    }
                }
                else if (points[i].first - min_height_d > points[i].second) {
                    if (horizon < max_horizon_d + 1) {
                        horizon = max_horizon_d + 1;
                        height = points[i].first;
                    }
                    else if (horizon == max_horizon_d + 1 && height > points[i].first) {
                        height = points[i].first;
                    }
                }
                else if (points[i].first - min_height_d <= points[i].second) {
                    if (horizon < max_horizon_d + 1) {
                        horizon = max_horizon_d + 1;
                        height = points[i].first;
                    }
                    else if (horizon == max_horizon_d + 1 && height > min_height_d + points[i].second) {
                        height = min_height_d + points[i].second;
                    }
                }
            }
            if (min_height_u <= points[i].first) {
                if (min_height_u == MIN_) {
                    if (horizon < max_horizon_u + 1) {
                        horizon = max_horizon_u + 1;
                        height = points[i].first;
                    }
                    else if (horizon == max_horizon_u + 1 && height > points[i].first) {
                        height = points[i].first;
                    }
                }
                else if (points[i].first - min_height_u > points[i].second) {
                    if (horizon < max_horizon_u + 1) {
                        horizon = max_horizon_u + 1;
                        height = points[i].first;
                    }
                    else if (horizon == max_horizon_u + 1 && height > points[i].first) {
                        height = points[i].first;
                    }
                }
                else if (points[i].first - min_height_u <= points[i].second) {
                    if (horizon < max_horizon_u + 1) {
                        horizon = max_horizon_u + 1;
                        height = points[i].first;
                    }
                    else if (horizon == max_horizon_u + 1 && height > min_height_u + points[i].second) {
                        height = min_height_u + points[i].second;
                    }
                }
            }
            num_of_horizon[0][i] = make_pair(height, horizon);
            cout << "[LJW] Hor - height : " << height << " horizon number : " << horizon << endl; 

            height = MIN_;
            horizon = 0;
            if (min_height_h < points[i].first - points[i].second) {
                if (min_height_h == MIN_) {
                    height = points[i+1].first - points[i+1].second;
                    horizon = max_horizon_h;
                }
                else {
                    height = min_height_h + points[i].second;
                    horizon = max_horizon_h;
                }
            }
            if (min_height_d < points[i].first - points[i].second) {
                if (min_height_d == MIN_) {
                    if (horizon < max_horizon_d) {
                        height = points[i+1].first - points[i+1].second;
                        horizon = max_horizon_d;
                    }
                }
                else {
                    if (horizon < max_horizon_d) {
                        height = min_height_d + points[i].second;
                        horizon = max_horizon_d;
                    }
                    else if (horizon == max_horizon_d && height > min_height_d + points[i].second) {
                        height = min_height_d + points[i].second;
                    }
                }
            }
            if (min_height_u < points[i].first - points[i].second) {
                if (min_height_u == MIN_) {
                    if (horizon < max_horizon_u) {
                        height = points[i+1].first - points[i+1].second;
                        horizon = max_horizon_u;
                    }
                }
                else {
                    if (horizon < max_horizon_u) {
                        height = min_height_u + points[i].second;
                        horizon = max_horizon_u;
                    }
                    else if (horizon == max_horizon_u && height > min_height_u+ points[i].second) {
                        height = min_height_u + points[i].second;
                    }
                }
            }
            num_of_horizon[1][i] = make_pair(height, horizon);
         //   cout << "[LJW] Down - height : " << height << " horizon number : " << horizon << endl; 

            height = MAX_;
            horizon = 0;
            if (min_height_h > points[i].first) {
                if (min_height_h == MAX_) {
                    height = points[i].first + points[i].second;
                    horizon = max_horizon_h;
                }
                else {
                    height = min_height_h + points[i].second;
                    horizon = max_horizon_h;
                }
            }
           // cout << "[LJW] h's - height : " << min_height_h << " horizon number : " << max_horizon_h << endl; 
           // cout << "[LJW] Up1 - height : " << height << " horizon number : " << horizon << endl; 
            if (min_height_d > points[i].first) {
                if (min_height_d == MAX_) {
                    if (horizon < max_horizon_d) {
                        height = points[i].first + points[i].second;
                        horizon = max_horizon_d;
                    }
                }
                else {
                    if (horizon < max_horizon_d) {
                        height = min_height_d + points[i].second;
                        horizon = max_horizon_d;
                    }
                    else if (horizon == max_horizon_d && height >  min_height_d + points[i].second) {
                        height = min_height_d + points[i].second;
                    }
                }
            }
           // cout << "[LJW] d's - height : " << min_height_d << " horizon number : " << max_horizon_d << endl; 
           // cout << "[LJW] Up2 - height : " << height << " horizon number : " << horizon << endl; 
            if (min_height_u > points[i].first) {
                if (min_height_u == MAX_) {
                    if (horizon < max_horizon_u) {
                        height = points[i].first + points[i].second + 1;
                        horizon = max_horizon_u;
                    }
                }
                else {
                    if (horizon < max_horizon_u) {
                        height = min_height_u + points[i].second;
                        horizon = max_horizon_u;
                    }
                    else if (horizon == max_horizon_u && height >  min_height_u + points[i].second) {
                        height = min_height_u + points[i].second;
                    }
                }
            }
            num_of_horizon[2][i] = make_pair(height, horizon);
          //  cout << "[LJW] u's - height : " << min_height_u << " horizon number : " << max_horizon_u << endl; 
          //  cout << "[LJW] Up - height : " << height << " horizon number : " << horizon << endl; 
        }

       // for (int i = 0; i < num_of_points; i++) {
       //     for (int j = 0;  j < 3; j++) {
       //         cout << "[LJW] TEST for points : " << i << " th, " << j << ": " << num_of_horizon[j][i].first << ", " << num_of_horizon[j][i].second << endl;
       //     }
       // }
        int count = max(num_of_horizon[0][num_of_points - 1].second, max(num_of_horizon[1][num_of_points - 1].second, num_of_horizon[2][num_of_points - 1].second));
		cout << "Case #" << test_case+1 << endl;
		cout << num_of_points - count << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
