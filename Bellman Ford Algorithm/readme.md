# বেলম্যান-ফোর্ড অ্যালগরিদম কিভাবে কাজ করে?

## ভূমিকা
বেলম্যান-ফোর্ড অ্যালগরিদম হল একটি গ্রাফ-ভিত্তিক অ্যালগরিদম যা **একটি উৎস নোড থেকে অন্যান্য সকল নোডের সর্বনিম্ন দূরত্ব** নির্ণয় করতে ব্যবহার করা হয়। এটি **নেগেটিভ ওয়েট** থাকা গ্রাফেও কাজ করে, তবে **নেগেটিভ সাইকেল** থাকলে সঠিকভাবে কাজ করতে পারে না। 

## অ্যালগরিদমের কাজের ধাপসমূহ

১. **শুরু করা**: প্রতিটি নোডের **দূরত্ব অসীম (∞)** সেট করতে হবে, তবে উৎস নোডের দূরত্ব হবে **০**।

২. **প্রসেস করা**: সমস্ত এজ (Edge) রিল্যাক্স করা হবে **(V-1) বার**, যেখানে **V** হলো গ্রাফের নোডের সংখ্যা। প্রতিটি এজ `(u, v, w)` নিয়ে যদি **দূরত্ব[u] + w < দূরত্ব[v]** হয়, তাহলে **দূরত্ব[v] আপডেট** করা হবে।

৩. **নেগেটিভ সাইকেল চেক করা**: যদি (V-1) বারের পরেও কোনো এজ রিল্যাক্স করা সম্ভব হয়, তাহলে বোঝা যাবে যে গ্রাফে **নেগেটিভ ওয়েট সাইকেল** আছে। 

## C++ কোড
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

void BellmanFord(int V, int E, vector<Edge>& edges, int source) {
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (auto edge : edges) {
            if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.dest]) {
                distance[edge.dest] = distance[edge.src] + edge.weight;
            }
        }
    }

    for (auto edge : edges) {
        if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.dest]) {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << distance[i] << endl;
    }
}

int main() {
    int V, E, source;
    cin >> V >> E;
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    cin >> source;
    BellmanFord(V, E, edges, source);
    return 0;
}
```

## সময় জটিলতা
- **O(V × E)** যেখানে V = নোড সংখ্যা এবং E = এজ সংখ্যা।
- সাধারণত **Dijkstra's Algorithm** অপেক্ষা ধীরগতির, তবে এটি **নেগেটিভ ওয়েট** থাকলেও কাজ করতে পারে।

## ব্যবহার ক্ষেত্র
- নেগেটিভ ওয়েট এজ বিশিষ্ট গ্রাফের **শর্টেস্ট পাথ** বের করার জন্য।
- নেগেটিভ সাইকেল আছে কিনা তা নির্ণয়ের জন্য।
- ট্রেডিং, নেটওয়ার্ক রাউটিং এবং অপারেশনাল রিসার্চে ব্যবহৃত হয়।

## উপসংহার
বেলম্যান-ফোর্ড অ্যালগরিদমের মাধ্যমে নেগেটিভ ওয়েট সহ গ্রাফের সর্বনিম্ন দূরত্ব নির্ণয় করা সম্ভব। যদিও এটি **ডাইকসট্রা অ্যালগরিদমের** তুলনায় ধীর, তবে এটি আরও জেনেরালাইজড এবং জটিল গ্রাফের ক্ষেত্রেও কাজ করে।