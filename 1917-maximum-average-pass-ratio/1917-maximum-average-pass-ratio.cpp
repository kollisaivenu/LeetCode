class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> maxHeap;

        for(int i=0;i<classes.size();i++){
            maxHeap.push({gain(classes[i][0], classes[i][1]), {classes[i][0], classes[i][1]}});
        }

        while(extraStudents--){
            int passes = maxHeap.top().second.first;
            int totalStudents = maxHeap.top().second.second;
            maxHeap.pop();
            maxHeap.push({gain(passes + 1, totalStudents + 1),
                          {passes + 1, totalStudents + 1}});
        }

        double totalPassRatio = 0;
        while (!maxHeap.empty()) {
            int passes = maxHeap.top().second.first;
            int totalStudents = maxHeap.top().second.second;
            maxHeap.pop();
            totalPassRatio += (double)passes / totalStudents;
        }

        return totalPassRatio/ classes.size();
    }

    double gain(int passes, int totalStudents){
        return (double)(passes + 1) / (totalStudents + 1) -
                   (double)passes / totalStudents;
    }
};