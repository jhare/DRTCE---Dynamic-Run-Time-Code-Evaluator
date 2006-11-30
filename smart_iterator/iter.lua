

local str = io.read ("*a");

print ("#include \"smart_iterator.h\"");

print ((string.gsub (str, "for %(int (.-) = (.-);(.-); ++(.-)%)", "for (_sint %1 (%2, \"%1\"); %3; %1.next ())")));
