#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int data[N];
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    sort(data, data + N);

    int cari;
    cout << "\nMencari kursi nomor: "; cin >> cari;

    int low = 0, high = N - 1, flag = 0;
    int posisi;
    float posisi1;

    while ((low <= high) && (cari >= data[low]) && (cari <= data[high])){
        posisi1 = (float)((cari - data[low]) / (data[high] - data[low])) * ((high - low) + low);
        posisi = floor(posisi1);

        if(data[posisi] == cari){
            flag = 1;
            break;
        }
        if(data[posisi] > cari){
            high = posisi - 1;
        }
        else{
            low = posisi + 1;
        }

    }
    
    
    cout << "\n\nHasil: ";
    if (flag == 1){
        cout << "Status: Tersedia" << endl;
        cout << "Detail : Ditemukan pada index ke[" << posisi << "]" << endl;
    }

    if(flag != 1){
        cout << "Status: Tidak Tersedia" << endl;
        cout << "Opsi terdekat : " << endl;
    }

    return 0;
}