class DSU {
public:

    // parent array
    vector<int> par;
    // sizes of groups
    vector<int> sizes;

    DSU(int size) {
        par = vector<int>(size);
        sizes = vector<int>(size);

        for (int i = 0; i < size; i++) {
            par[i] = i;
            sizes[i] = 1;
        }
    }


    int find(int x) {
        if (par[x] != x) {
            // path compression
            par[x] = find(par[x]);
        }

        return par[x];
    }

    void dsu_union (int x, int y) {
        int par_x = find(x);
        int par_y = find(y);

        // avoid readding sizes.
        if (par_x == par_y) return;

        // union by size: attach smaller to larger
        if (sizes[par_x] >= sizes[par_y]) {
            par[par_y] = par_x;
            sizes[par_x] += sizes[par_y];
        } else {
            par[par_x] = par_y;
            sizes[par_y] += sizes[par_x];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // if two accounts have a common email, merge them
        // these common email accounts will definitely have the same name

        DSU dsu(accounts.size());

        unordered_map<string, int> email_sets;

        // for each account in list
        for (int i = 0; i < accounts.size(); i++) {
            vector<string> account = accounts[i];

            // string name = account[0];

            // for each email in account
            for (int j = 1; j < account.size(); j++) {
                string email = account[j];

                if (email_sets.find(email) == email_sets.end()) {
                    // this email is unseen

                    // say it belongs to a new set
                    email_sets[email] = i;
                } else {
                    // email has been seen
                    dsu.dsu_union(i, email_sets[email]);
                }
            }
        }
        
        // collect emails
        unordered_map<int, vector<string>> account_emails;

        for (auto& [email, set] : email_sets) {
            // need dsu.find because set may be a child.
            account_emails[dsu.find(set)].push_back(email);
        }

        // want emails in sorted order
        vector<vector<string>> res;
        for (auto & [set, emails] : account_emails) {
            // get account name
            string account_name = accounts[set][0];

            vector<string> account_entry;
            account_entry.push_back(account_name);

            // sort emails
            sort(emails.begin(), emails.end());

            // add emails onto end
            account_entry.reserve(account_entry.size() + emails.size());
            account_entry.insert(account_entry.end(), emails.begin(), emails.end());
        
            res.push_back(account_entry);
        }

        return res;
    }
};