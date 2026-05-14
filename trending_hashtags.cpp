#include<iostream>
using namespace std;

int main() {

    string hashtag[5] = {"#AI", "#IPL", "#Tech", "#AI", "#IPL"};
    int freq[5] = {0};

    for(int i=0; i<5; i++) {

        if(freq[i] == -1)
            continue;

        freq[i] = 1;

        for(int j=i+1; j<5; j++) {

            if(hashtag[i] == hashtag[j]) {
                freq[i]++;
                freq[j] = -1;
            }
        }
    }

    cout<<"Trending Hashtags:\n";

    for(int i=0; i<5; i++) {

        if(freq[i] != -1)
            cout<<hashtag[i]<<" -> "<<freq[i]<<endl;
    }

    return 0;
}
