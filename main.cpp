#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <sstream>
#include <string>

void bfs(const std::vector<std::vector<bool>>& graph, int startv = 1);

int main() {
  //std::cout << "Hello World!\n";
  std::ifstream infile("input.txt");
  int size{};
  infile >> size;
  //std::cout<<size<<"\n";
  int startv = 0;
  std::cout<<"В графе "<<size<<" вершин. Введите номер вершины, с которой начнётся обход: ";
  std::cin >> startv;
  if(startv > size || startv < 1){
    startv = 1;
    std::cout << "Неверное значение. Будет использована вершина номер 1.\n";
  }
  std::vector<std::vector<bool>> graph(size);
  int i{};
  std::string str;
  while(std::getline(infile,str)){
    //std::cout<<str<<"\n";
    if(str.empty()) continue;
    std::istringstream ss(str);
    bool v{};
    while(ss>>v){
       graph[i].push_back(v);
    }
    i++;
  }
  /*std::cout<<"\nPrinting graph:\n";
  for(const auto& vec:graph){
    for(const auto& v:vec){
       std::cout<<v<<" ";
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;*/
  std::cout<<"Порядок обхода вершин: ";
  bfs(graph, startv);
}

void bfs(const std::vector<std::vector<bool>>& graph, int startv){
  std::vector<bool> visited(graph.size(),false);
  //std::vector<int> queue;
  int size = graph.size();
  startv--;
  std::deque<int> vqueue;
  for(int c = startv, v = c % size; c < size + startv; c++){
  //for(int v{}; v<graph.size();v++){
    v = c % size;
    if(!visited[v]){
      vqueue.push_back(v);
      visited[v] = true; //MARKING AS VISITED SHOULD BE DONE WHEN ADDING TO QUEUE!
      while(!vqueue.empty()){
        int vertex = vqueue.front();
        //visited[vertex] = true;//WRONG! MARKING AS VISITED SHOULD BE DONE WHEN ADDING TO QUEUE!
        std::cout<<vertex+1<<" ";
        //std::cout<<"\n";
        vqueue.pop_front();
        //std::cout<<"Looking for neighbors of "<<vertex+1<<":\n";
        for(int w{}; w<graph.size(); w++){
          if(graph[vertex][w] && !visited[w]){
            //std::cout<<w+1<<"\n";
            vqueue.push_back(w);
            visited[w] = true; //MARKING AS VISITED SHOULD BE DONE WHEN ADDING TO QUEUE!
          }
        }
      }
    }
  }
}
