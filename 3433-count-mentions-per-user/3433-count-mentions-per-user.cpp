class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int>ans(numberOfUsers, 0);
        vector<int>online(numberOfUsers, -1);
        sort(events.begin(), events.end(), compare_messages_by_timestamp); 
        for(int i=0;i<events.size();i++){
            if(events[i][0] == "MESSAGE") {
                if(events[i][2] == "ALL") {
                    for(int j=0;j<numberOfUsers;j++){
                        ans[j]++;
                    }
                } else if(events[i][2] == "HERE") {
                    int timestamp = stoi(events[i][1]);

                    for(int j=0;j<numberOfUsers;j++) {
                        if(online[j] == -1) {
                            ans[j]++;
                        } else if(timestamp >= online[j]){
                            ans[j]++;
                            online[j] = -1;
                        }
                    } 
                } else {
                    vector<int>users = getUsers(events[i][2]);

                    for(int user: users) {
                        ans[user]++;
                    }
                }
            } else if(events[i][0] == "OFFLINE") {
                int timestamp = stoi(events[i][1]);
                int user = stoi(events[i][2]);
                online[user] = timestamp + 60;
            }
        }

        return ans;
        
    }
    vector<int> getUsers(string &str) {
        vector<int>users;
        for(int i=0;i<str.length();i++) {
            if(str[i] == 'i') {
                i=i+2;
                int user = 0;
                while(str[i]-'0' >= 0 && str[i] - '0' <= 9){
                    user = user*10 + str[i]-'0';
                    i++;
                }
                users.push_back(user);
            }
        }

        return users;
    }

    static bool compare_messages_by_timestamp(vector<string>&a, vector<string>&b) {
        int ts_a = stoi(a[1]);
        int ts_b = stoi(b[1]);

        if(ts_a == ts_b) {
            if(a[0] == "OFFLINE") {
                return true;
            }

            return false;
        }
        return ts_a < ts_b;
    }
};