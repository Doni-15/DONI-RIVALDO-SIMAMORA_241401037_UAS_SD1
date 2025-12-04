#include <bits/stdc++.h>
using namespace std;

struct Tetangga{
    string nama_kota;
    int jarak;
};

typedef pair<string, Tetangga> iPair;

void DjiktsrAlgorithm(string kota_awal, string kota_tujuan, vector<vector<iPair>> adj);

int main(){
    system("cls");
    
    // Medan, Tebing tinggi, Brastagi, Pematang siantar, Sidikalang, Perapat
    int V = 5;
    vector<vector<iPair>> adj(V);
    // Medan
    adj[0].push_back({"Medan", {"Tebing TInggi", 90}});
    adj[0].push_back({"Medan", {"Berastagi", 60}});

    // Tebing Tinggi
    adj[1].push_back({"Tebing Tinggi", {"Pematang Siantar", 50}});
    
    // Brastagi
    adj[2].push_back({"Brastagi", {"Sidikalang", 90}});
    adj[2].push_back({"Brastagi", {"Pematang Siantar", 80}});
    
    // Pematang Siantar
    adj[3].push_back({"Pematang Siantar", {"Prapat", 45}});
    adj[3].push_back({"Pematang Siantar", {"Sidikalang", 65}});
    
    // Sidikalang 
    adj[4].push_back({"Sidikalang", {"Prapat", 120}});
    
    return 0;
}

const int INF = numeric_limits<int>::max();

void DjiktsrAlgorithm(string kota_awal, string kota_tujuan, vector<vector<iPair>>& adj){
    map<string, int> dist;
    map<string, string> ruteSebelumnya;
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    for (const auto& tetanggaList : adj) {
        for (const auto& tetangga : tetanggaList) {
            dist[tetangga.first] = INF;
        }
    }
    dist[kota_awal] = 0;
    pq.push({0, {kota_awal, 0}});   
    while (!pq.empty()) {
        string kota_sekarang = pq.top().second.nama_kota;
        pq.pop();

        for (const auto& tetangga : adj) {
            if (tetangga.first == kota_sekarang) {
                for (const auto& next : tetangga.second) {
                    string kota_tetangga = next.nama_kota;
                    int jarak = next.jarak;

                    if (dist[kota_sekarang] + jarak < dist[kota_tetangga]) {
                        dist[kota_tetangga] = dist[kota_sekarang] + jarak;
                        ruteSebelumnya[kota_tetangga] = kota_sekarang;
                        pq.push({dist[kota_tetangga], {kota_tetangga, jarak}});
                    }
                }
            }
        }
    }
    if (dist[kota_tujuan] == INF) {
        cout << "Tidak ada rute dari " << kota_awal << " ke " << kota_tujuan << endl;
        return;
    }
    cout << "Jarak terpendek dari " << kota_awal << " ke " << kota_tujuan << " adalah " << dist[kota_tujuan] << " km" << endl;
    vector<string> rute;
    for (string at = kota_tujuan; at != ""; at = ruteSebelumnya[at]) {
        rute.push_back(at);
    }
    reverse(rute.begin(), rute.end());
    cout << "Rute: ";
    for (const auto& kota : rute) {
        cout << kota;
        if (kota != kota_tujuan) {
            cout << " -> ";
        }
    }
    cout << endl;
}