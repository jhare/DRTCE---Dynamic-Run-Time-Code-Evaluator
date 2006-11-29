

local str = io.read ("*a");

print ("#include \"drtce.h\"");

--print (string.gsub (str, "(%w+)[^%w]*([%+%-%=%*%/%&%|]+)([^;]+);", "drtce (%1, %2, %3);"));
print ((string.gsub (str, "for.-%((.-);(.-);([^%)]-)%)", "for (%1; %2; drtce_for (%1, %2, %3))")));
