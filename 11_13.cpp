#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int binary_search_int(const vector<int>& data, int target) {
    int left = 0, right = data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] == target) {
            return mid;
        }
        else if (data[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int binary_search_string(const vector<string>& data, const string& target) {
    int left = 0, right = data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] == target) {
            return mid;
        }
        else if (data[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;  // If not found
}

int main() {
    string T;
    int n, q;   // Number of elements in data and number of queries
    while (cin >> T >> n >> q) {
        vector<string> data_str;
        vector<int> data_int;

        // Read n data elements
        if (T == "i") {
            // For int type
            data_int.resize(n);
            for (int i = 0; i < n; i++) {
                cin >> data_int[i];
            }
        }
        else if (T == "s") {
            // For string type
            data_str.resize(n);
            for (int i = 0; i < n; i++) {
                cin >> data_str[i];
            }
        }

        // Sort the data before performing binary search
        if (T == "i") {
            sort(data_int.begin(), data_int.end());
        }
        else if (T == "s") {
            sort(data_str.begin(), data_str.end());
        }

        // Process q queries
        for (int i = 0; i < q; i++) {
            if (T == "i") {
                int target;
                cin >> target;
                int result = binary_search_int(data_int, target);
                cout << result << endl;
            }
            else if (T == "s") {
                string target;
                cin >> target;
                int result = binary_search_string(data_str, target);
                cout << result << endl;
            }
        }
    }

    return 0;
}
