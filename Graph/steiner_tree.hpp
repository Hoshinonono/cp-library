template <class T> std::vector<T> steiner_tree(std::vector<std::vector<std::pair<int, T>>> &G, 
								std::vector<int> &terminal){
    const int N = G.size(), t = terminal.size();
	if(t == 0) {
		std::vector<T> ans(N);
		return ans;
	}
	std::vector<std::vector<T>> dp(1 << t, std::vector<T>(N, std::numeric_limits<T>::max() / 2));
	for(int i = 0; i < t; i++){
		assert(0 <= terminal[i] && terminal[i] < N);
		dp[1 << i][terminal[i]] = 0;
	}
	std::priority_queue<std::pair<T, int>, 
		std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> pq;
	for(int S = 1; S < (1 << t); S++){
		for(int v = 0; v < N; v++){
			for(int U = S & (S - 1); U > 0; U = (U - 1) & S){
				dp[S][v] = std::min(dp[S][v], dp[U][v] + dp[U ^ S][v]);
			}
		}
		for(int v = 0; v < N; v++) pq.emplace(dp[S][v], v);
		while(!pq.empty()){
			auto [d, v] = pq.top();
			pq.pop();
			if(d > dp[S][v])continue;
			for(auto &&[u, w] : G[v]){
				if(d + w >= dp[S][u]) continue;
				dp[S][u] = d + w;
				pq.emplace(dp[S][u], u);
			}
		}
	}
	return dp.back();
}