	auto start = chrono::steady_clock::now();

	/**
	 * 
	 * Code...
	 * 
	 * */ 

	auto finish = std::chrono::steady_clock::now();
	double TIME = chrono::duration_cast<chrono::duration<double> >(finish - start).count();
	cout << "TIME: " << TIME << endl;
	
