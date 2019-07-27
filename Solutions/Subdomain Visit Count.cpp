class Solution {
public:
    
    pair<int, string> parse(const string& domain) {
        stringstream ss(domain);
        int count = 0;
        ss >> count;
        string domain_parsed = "";
        ss >> domain_parsed;
        return {count, domain_parsed};
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domain_counter;
        
        pair<int, string> parsed;
        int count;
        string domain_parsed = "";
        string curr_domain = "";
        for (const string& domain : cpdomains) {
            parsed = parse(domain);
            count = parsed.first;
            domain_parsed = parsed.second;
            
            curr_domain = "";
            for (int i = int{domain_parsed.size()} - 1; i >= 0; i--) {
                if (domain_parsed[i] == '.') {
                    domain_counter[curr_domain] += count;
                }
                curr_domain += domain_parsed[i];
            }
            domain_counter[curr_domain] += count;
        }
        
        vector<string> new_cpdomains;
        for (auto& i : domain_counter) {
            string domain = i.first;
            reverse(domain.begin(), domain.end());
            new_cpdomains.push_back(string(to_string(i.second) + " " + domain));
        }
        
        return new_cpdomains;
    }
    
};
