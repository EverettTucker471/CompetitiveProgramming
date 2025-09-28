#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

double dist(int x1, int y1, int x2, int y2, double p_x, double p_y) {
    return std::sqrt(std::pow(p_x - x1, 2) + std::pow(p_y - y1, 2)) +
           std::sqrt(std::pow(p_x - x2, 2) + std::pow(p_y - y2, 2));
}

void ellipse_eclipse() {
    int x1, y1, x2, y2, a;
    cin >> x1 >> y1 >> x2 >> y2 >> a;
    double center_x = ((double) x1 + x2) / 2;
    double center_y = ((double) y1 + y2) / 2;

    // Finding min x
    double left_x = x1 - a; // Always outside the ellipse
    double right_x = x1;  // Always inside the ellipse

    while (right_x - left_x > 0.000001) {
        // Ternary searchDFS to optimize bottom_y and top_y
        double bottom_y = y1 - a;
        double top_y = y1 + a;
        while (top_y - bottom_y > 0.000001) {
            double m1 = (top_y + 2 * bottom_y) / 3;
            double m2 = (2 * top_y + bottom_y) / 3;
            double d1 = dist(x1, y1, x2, y2, left_x, m1);
            double d2 = dist(x1, y1, x2, y2, left_x, m2);
            if (d1 > d2) {
                bottom_y = m1;
            } else {
                top_y = m2;
            }
        }

        double optimal_y = (bottom_y + top_y) / 2;
        double mid = (left_x + right_x) / 2;

        if (dist(x1, y1, x2, y2, mid, optimal_y) < a) {
            right_x = mid;
        } else {
            left_x = mid;
        }
    }

    double final_left_x = left_x;
    double final_right_x = 2 * center_x - left_x;

    // Now the same thing for y
    double b_y = y1 - a; // Always outside the ellipse
    double t_y = y1 + a;  // Always inside the ellipse

    while (t_y - b_y > 0.000001) {
        // Ternary searchDFS to optimize l_x and r_x
        double l_x = x1 - a;
        double r_x = x2 + a;
        while (r_x - l_x > 0.000001) {
            double m1 = (r_x + 2 * l_x) / 3;
            double m2 = (2 * r_x + l_x) / 3;
            double d1 = dist(x1, y1, x2, y2, m1, b_y);
            double d2 = dist(x1, y1, x2, y2, m2, b_y);
            if (d1 > d2) {
                l_x = m1;
            } else {
                r_x = m2;
            }
        }

        double optimal_x = (l_x + r_x) / 2;
        double mid = (b_y + t_y) / 2;

        if (dist(x1, y1, x2, y2, optimal_x, mid) < a) {
            t_y = mid;
        } else {
            b_y = mid;
        }
    }

    double final_bottom_y = b_y;
    double final_top_y = 2 * center_y - b_y;

    printf("%f6", final_left_x);
    cout << " ";
    printf("%f6", final_bottom_y);
    cout << " ";
    printf("%f6", final_right_x);
    cout << " ";
    printf("%f6", final_top_y);
}