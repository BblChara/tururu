#include <fstream>
#include <iostream>

struct stack1
{
    int size;
    int last = -1;
    long long* stck;
    long long* stckmin;

    stack1() {
        size = 0;
        stck = nullptr;
        stckmin = nullptr;
    }

    long long choose_min(long long x) {
        if ((last == 0) | (x < stckmin[last - 1])) return x;
        return stckmin[last - 1];
    }
    void push(long long x) {
        if (size == 0) {
            stck = new long long[1];
            stckmin = new long long[1];
            last++;
            stck[last] = x;
            stckmin[last] = x;
            size = 1;

        }
        else if (size - last - 1) {
            last++;
            stck[last] = x;
            stckmin[last] = choose_min(x);
        }
        else {
            size *= 2;
            long long* tmp = new long long[size];
            long long* tmp1 = new long long[size];
            for (long i = 0; i < last + 1; i++) {
                tmp[i] = stck[i];
                tmp1[i] = stckmin[i];
            }
            delete[] stck;
            delete[] stckmin;
            stck = tmp;
            stckmin = tmp1;
            last++;
            stck[last] = x;
            stckmin[last] = choose_min(x);
        }
    }


    long long pop() {
        last--;
        return stck[last + 1];
    }

    long long getmin() {
        return  stckmin[last];
    }

    bool empty() {
        return  last == -1;
    }
};

struct queue1 {

    stack1 pushstack;
    stack1 popstack;

    void push(long x) {
        pushstack.push(x);
    }

    long long pop() {
        if (popstack.empty()) {
            while (!pushstack.empty()) {
                popstack.push(pushstack.pop());
            }
        }
        return popstack.pop();
    }
    long get_min() {
        if (popstack.empty()) return pushstack.getmin();
        if (pushstack.empty()) return popstack.getmin();
        return std::min(pushstack.getmin(), popstack.getmin());

    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return 1;
    }
    std::ifstream inFile(argv[1]);
    if (!inFile) {
        return 2;
    }
    std::ofstream outFile(argv[2]);
    if (!outFile) {
        return 3;
    }

    queue1 que;
    int non;
    inFile >> non;
    for (int i = 0; i < non; i++) {
        std::string command;
        long long chis;
        inFile >> command;
        switch (command[0])
        {
        case '+':
            inFile >> chis;
            que.push(chis);
            break;
        case '-':
            que.pop();
            break;
        case '?':
            outFile << que.get_min() << '\n';
            break;
        }

    }

    inFile.close();
    outFile.close();
    return 0;
}
