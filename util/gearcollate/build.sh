g++ -g -fPIC -std=c++11 -dynamiclib entry.cpp ../../core/StringCompare.cpp ../../core/MusicSort.cpp -I../../core/public -o libgearcollate.dylib
cp libgearcollate.dylib ~/Library/Containers/com.treasurebox.gear/Data/Library/Application\ Support/libgearcollate.dylib