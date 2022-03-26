add_rules("mode.debug", "mode.release")

set_kind("binary")
add_files("*.cpp")

target("pic2str")
    if is_host("windows") then 
        add_includedirs("F:\\code\\useful\\opencv\\4.5.5\\install\\include")
        add_linkdirs("F:\\code\\useful\\opencv\\4.5.5\\install\\x64\\vc17\\lib")
        add_links("opencv_world455")
    elseif is_host("linux") then 
        add_includedirs("/usr/local/include/opencv4")
        add_linkdirs("/usr/local/lib")
        add_links("opencv_world")
    end
target_end()
