-- A tool file for manipulating cable.
-- version 1.0

require("Cable")

-- function pins_of_side_A_connected_to(pin_num)
	-- if pin_num > #Cable // 2 or pin_num < 1 then
		-- error("pin number out of range!")
	-- end
	-- local res = {}
	-- local conn_to_B = Cable[pin_num * 2 - 1]
	-- if #conn_to_B == 0 then
		-- return res
	-- end
	-- for k, v in pairs(conn_to_B) do
		-- for i = 1, #Cable, 2 do
			-- if i ~= pin_num * 2 - 1 then
				-- for tk, tv in pairs(Cable[i]) do
					-- if v == tv then
						-- table.insert(res, i // 2 + 1)
					-- end
				-- end
			-- end
		-- end
	-- end
	-- return res
-- end

-- function pins_of_side_B_connected_to(pin_num)
	-- if pin_num > #Cable // 2 or pin_num < 1 then
		-- error("pin number out of range!")
	-- end
	-- local res = {}
	-- local conn_to_A = Cable[pin_num * 2]
	-- if #conn_to_A == 0 then
		-- return res
	-- end
	-- for k, v in pairs(conn_to_A) do
		-- for i = 0, #Cable, 2 do
			-- if i ~= pin_num * 2 and i ~= 0 then
				-- for tk, tv in pairs(Cable[i]) do
					-- if v == tv then
						-- table.insert(res, i // 2)
					-- end
				-- end
			-- end
		-- end
	-- end
	-- return res
-- end

function get_input(out_pin, in_pin, side, step)
	if in_pin > #Cable // 2 or in_pin < 1 or out_pin > #Cable // 2 or out_pin < 1 then
		error("pin number out of range!")
	end
	
	if step == nil then
		-- local conn = {}
		-- if side == 'A' then
			-- conn = pins_of_side_A_connected_to(out_pin)
		-- elseif side == 'B' then
			-- conn = pins_of_side_B_connected_to(out_pin)
		-- else
			-- error("bad side identifier, A and B is allowed!")
		-- end
		-- for k, v in pairs(conn) do
			-- if v == in_pin then
				-- return 1
			-- end
		-- end
		-- return 0
		if side == 'A' then
			for i = 0, #Cable, 2 do
				if i > 0 and #Cable[i] > 1 then
					for k, v in pairs(Cable[i]) do
						if out_pin == v then
							for kt, vt in pairs(Cable[i]) do
								if in_pin == vt then
									return 1
								end
							end
						end
					end
				end
			end
			return 0
		end
		if side == 'B' then
			for i = 1, #Cable, 2 do
				if #Cable[i] > 1 then
					for k, v in pairs(Cable[i]) do
						if out_pin == v then
							for kt, vt in pairs(Cable[i]) do
								if in_pin == vt then
									return 1
								end
							end
						end
					end
				end
			end
			return 0
		end
	end

	if step == 'DisA' and side == 'A' then
		if #(Cable[2 * out_pin - 1]) ~= 0 and #(Cable[2 * in_pin - 1]) ~= 0 then
			return 1
		end
		return 0
	end
	if step == 'DisB' and side == 'B' then
		if #(Cable[2 * out_pin]) ~= 0 and #(Cable[2 * in_pin]) ~= 0 then
			return 1
		end
		return 0
	end
	
end

function get_pin_count()
	return #Cable // 2
end