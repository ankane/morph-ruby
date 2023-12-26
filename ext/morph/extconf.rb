require "mkmf-rice"

abort "Missing stdc++" unless have_library("stdc++")

if Dir.exist?("/opt/homebrew")
  $INCFLAGS += " -I/opt/homebrew/include"
  $LDFLAGS += " -L/opt/homebrew/lib"
end

abort "Missing ntl" unless have_library("ntl")
abort "Missing helib" unless have_library("helib")
abort "Missing morph" unless have_library("morph")

$CXXFLAGS << " -std=c++17"

create_makefile("morph/ext")
