#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> string_to_vector_int(string s) {
    vector<int> v;
    for (auto c : s) {
        v.push_back(c - '0');
    }
    return v;
}

struct Node {
    int value;
    Node * grey_line;
    Node * red_line;
};

class Mod7 {
public:
    Mod7() {
        node0 -> grey_line = node1;
        node1 -> grey_line = node2;
        node2 -> grey_line = node3;
        node3 -> grey_line = node4;
        node4 -> grey_line = node5;
        node5 -> grey_line = node6;
        node6 -> grey_line = node0;
        
        node0 -> red_line = node0;
        node1 -> red_line = node3;
        node2 -> red_line = node6;
        node3 -> red_line = node2;
        node4 -> red_line = node5;
        node5 -> red_line = node1;
        node6 -> red_line = node4;

        node0 -> value = 0;
        node1 -> value = 1;
        node2 -> value = 2;
        node3 -> value = 3;
        node4 -> value = 4;
        node5 -> value = 5;
        node6 -> value = 6;
    }

    int remainder(string number) {
        // change this member function to make the test pass
        vector<int> v;
        v=string_to_vector_int(number);
        return calculate_mod(v);
    }

     ~Mod7() {
        delete node0;
        delete node1;
        delete node2;
        delete node3;
        delete node4;
        delete node5;
        delete node6;
    }

    int calculate_mod(vector<int> const& v) {
        Node* temp{node0};
        for (int i{}; i < v.size(); i++) {
            for (int j{}; j < v[i]; j++) {
                temp = temp -> grey_line;
            }
            if (i + 1 < v.size()) {
                temp = temp -> red_line;
            }
        }
        return temp -> value;
    }

private:

    // Insert extra data members if needed 
    Node * node0{new Node{}};
    Node * node1{new Node{}};
    Node * node2{new Node{}};
    Node * node3{new Node{}};
    Node * node4{new Node{}};
    Node * node5{new Node{}};
    Node * node6{new Node{}};
};


int main() {
    string test1{"243"};

    Mod7 modder{};

    if (modder.remainder("243") == 5) {
        cout << "Correct" << endl;
    }
    else {
        cout << modder.remainder("243") << endl;
    }

    if (modder.remainder("11111111111111111111111111111") == 2) {
        cout << "Correct" << endl;
    }

    // more test cases here
}
