#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include<algorithm>

using namespace std;

class Station {
public:
    string name;
    int id;

    Station(string name, int id) : name(name), id(id) {}
};

class MetroNetwork {
public:
    unordered_map<int, vector<pair<int, double>>> adjList; // adjacency list for the graph
    unordered_map<string, int> stationToId;
    unordered_map<int, string> idToStation;
    unordered_map<int, double> dist;

    void addStation(string name, int id) {
        stationToId[name] = id;
        idToStation[id] = name;
    }

    void addRoute(int from, int to, double time, double dist) {
        adjList[from].push_back(make_pair(to, time));
        adjList[to].push_back(make_pair(from, time)); // assuming bidirectional routes
        this->dist[to] = dist;
        this->dist[from] = dist;
    }
};
vector<int> dijkstra(MetroNetwork &network, int start, int end, double &totalTime, double &totalDist) {
    int n = network.adjList.size();
    vector<double> distance(n, numeric_limits<double>::max());
    vector<int> parent(n, -1);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    distance[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == end) break;

        for (auto &neighbor : network.adjList[u]) {
            int v = neighbor.first;
            double weight = neighbor.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    totalTime = distance[end];
    totalDist = 0;
    vector<int> path;
    for (int at = end; at != -1; at = parent[at]) {
        path.push_back(at);
        totalDist += network.dist[at];
    }
    reverse(path.begin(), path.end());
    return path;
}
void initializeHyderabadMetro(MetroNetwork &network) {
    // Add stations
    network.addStation("Miyapur", 0);
    network.addStation("JNTU College", 1);
    network.addStation("KPHB Colony", 2);
    network.addStation("Kukatpally", 3);
    network.addStation("Balanagar", 4);
    network.addStation("Moosapet", 5);
    network.addStation("Bharat Nagar", 6);
    network.addStation("Erragadda", 7);
    network.addStation("ESI Hospital", 8);
    network.addStation("SR Nagar", 9);
    network.addStation("Ameerpet", 10);
    network.addStation("Punjagutta", 11);
    network.addStation("Irrum Manzil", 12);
    network.addStation("Khairatabad", 13);
    network.addStation("Lakdikapul", 14);
    network.addStation("Assembly", 15);
    network.addStation("Nampally", 16);
    network.addStation("Gandhi Bhavan", 17);
    network.addStation("Osmania Medical College", 18);
    network.addStation("MG Bus Station", 19);
    network.addStation("Malakpet", 20);
    network.addStation("New Market", 21);
    network.addStation("Musarambagh", 22);
    network.addStation("Dilsukhnagar", 23);
    network.addStation("Chaitanyapuri", 24);
    network.addStation("Victoria Memorial", 25);
    network.addStation("LB Nagar", 26);
    network.addStation("Nagole", 27);
    network.addStation("Uppal", 28);
    network.addStation("Stadium", 29);
    network.addStation("NGRI", 30);
    network.addStation("Habsiguda", 31);
    network.addStation("Tarnaka", 32);
    network.addStation("Mettuguda", 33);
    network.addStation("Secunderabad East", 34);
    network.addStation("Parade Grounds", 35);
    network.addStation("Paradise", 36);
    network.addStation("Rasoolpura", 37);
    network.addStation("Prakash Nagar", 38);
    network.addStation("Begumpet", 39);
    network.addStation("Madhura Nagar", 40);
    network.addStation("Yousufguda", 41);
    network.addStation("Jubilee Hills Road 5", 42);
    network.addStation("Jubilee Hills Check Post", 43);
    network.addStation("Peddamma Temple", 44);
    network.addStation("Madhapur", 45);
    network.addStation("Durgam Cheruvu", 46);
    network.addStation("Hitec City", 47);
    network.addStation("Raidurg", 48);
    network.addStation("Secunderabad West", 49);
    network.addStation("Gandhi Hospital", 50);
    network.addStation("Musheerbad", 51);
    network.addStation("RTC X Roads", 52);
    network.addStation("Chikadpally", 53);
    network.addStation("Narayanguda", 54);
    network.addStation("Sultan Bazar", 55);
    
    
    

    // Add routes (from, to, travel time in minutes, fare)
    network.addRoute(0, 1, 3, 1.8);
    network.addRoute(1, 2, 3, 1.5);
    network.addRoute(2, 3, 3, 1.5);
    network.addRoute(3, 4, 2, 1.4);
    network.addRoute(4, 5, 2, 0.7);
    network.addRoute(5, 6, 2, 1);
    network.addRoute(6, 7, 2, 0.8);
    network.addRoute(7, 8, 3, 1.2);
    network.addRoute(8, 9, 2, 0.7);
    network.addRoute(9, 10, 1, 0.7);
    network.addRoute(10, 11, 2, 1.1);
    network.addRoute(11, 12, 2, 1);
    network.addRoute(12, 13, 3, 1.2);
    network.addRoute(13, 14, 3, 1.1);
    network.addRoute(14, 15, 2, 1);
    network.addRoute(15, 16, 2, 0.7);
    network.addRoute(16, 17, 2, 0.8);
    network.addRoute(17, 18, 2, 1);
    network.addRoute(18, 19, 2, 0.6);
    network.addRoute(19, 20, 2, 0.9);
    network.addRoute(20, 21, 2, 1.1);
    network.addRoute(21, 22, 2, 1);
    network.addRoute(22, 23, 5, 1.5);
    network.addRoute(23, 24, 2, 1.1);
    network.addRoute(24, 25, 2, 1.2);
    network.addRoute(25, 26, 3, 1.4);
    network.addRoute(27, 28, 2, 1);
    network.addRoute(28, 29, 2, 1.1);
    network.addRoute(29, 30, 2, 1.2);
    network.addRoute(30, 31, 3, 0.9);
    network.addRoute(31, 32, 3, 1.6);
    network.addRoute(32, 33, 2, 1.3);
    network.addRoute(33, 34, 3, 1.9);
    network.addRoute(34, 35, 3, 1.6);
    network.addRoute(35, 36, 2, 1.2);
    network.addRoute(36, 37, 2, 1);
    network.addRoute(37, 38, 2, 1.1);
    network.addRoute(38, 39, 2, 1.4);
    network.addRoute(39, 10, 2, 1.6);
    network.addRoute(10, 40, 1, 0.7);
    network.addRoute(40, 41, 2, 1.4);
    network.addRoute(41, 42, 1, 0.9);
    network.addRoute(42, 43, 3, 1.4);
    network.addRoute(43, 44, 2, 1);
    network.addRoute(44, 45, 3, 1.5);
    network.addRoute(45, 46, 4, 1.7);
    network.addRoute(46, 47, 1, 0.8);
    network.addRoute(47, 48, 3, 1.5);
    network.addRoute(35, 49, 2, 1.3);
    network.addRoute(49, 50, 2, 1.2);
    network.addRoute(50, 51, 2, 0.9);
    network.addRoute(51, 52, 2, 1.2);
    network.addRoute(52, 53, 2, 0.8);
    network.addRoute(53, 54, 2, 0.9);
    network.addRoute(54, 55, 2, 1.3);
    network.addRoute(55, 19, 2, 0.7);
    
}
int main() {
    MetroNetwork network;
    initializeHyderabadMetro(network);

    string startStation, endStation;
    cout << "Enter the start station: ";
    getline(cin, startStation);
    cout << "Enter the end station: ";
    getline(cin, endStation);

    int startId = network.stationToId[startStation];
    int endId = network.stationToId[endStation];

    double totalTime, totalDist;
    vector<int> path = dijkstra(network, startId, endId, totalTime, totalDist);

    cout << "Shortest path from " << startStation << " to " << endStation << ":" << endl;
    for (int id : path) {
        cout << network.idToStation[id] << " ";
    }
    cout << endl;
    cout << "Time: " << totalTime << " minutes" << endl;
    cout << "Distance: " << totalDist << " km" << endl;

    return 0;
}