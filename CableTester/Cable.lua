-- A script file to describe the pins' connection relationship between one cable's two-end plugs
-- version 1.0


-- Since the cable plugs are finally adapted to standard plugs, 
-- this script file numbers the pins directly in order.
Cable = {
	{2}, {}, -- No.1 pair of pins, {2} indicates No.1 pin of side A connects to No.2 pin of side B, {} indicates No.1 pin of side B connects to nothing.
	{5}, {1}, -- 2
	{9}, {5}, -- 3
	{6}, {9}, -- 4
	{3}, {2}, -- 5
	{9}, {4}, -- 6
	{10}, {8}, -- 7
	{7, 8}, {8}, -- 8
	{4}, {3, 6}, -- 9
	{}, {7} -- 10
}

