class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;

	for(int i=0;i<queries.size();i++){

		string str = queries[i];

		int j = 0, k = 0;

		while(k < str.length() && j < pattern.length()){
			if(str[k] != pattern[j] && !(str[k]>=65 && str[k]<=90)) {
				k++;
			}
			else if(str[k] == pattern[j] ){
				k++,j++;
			}
            else
                break;
		}

		if(j != pattern.length()){
			ans.push_back(false);
		}
		else{
			bool chk = true;

			while(k < str.length()){
				if( str[k] >= 65 && str[k] <= 90){
					chk = false;
					break;
				}
				k++;
			}

			ans.push_back(chk);
		}
	}

	return ans;
    }
};