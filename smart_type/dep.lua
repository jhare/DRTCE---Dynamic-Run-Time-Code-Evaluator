

local str = io.read ("*a");

print ("#include \"smart_type.h\"");

print ((string.gsub (str, "int[^;%{%}]-([%w_]+)[^;%{%}]-=(.-);", "_int %1 (%2, \"%1\");")));
