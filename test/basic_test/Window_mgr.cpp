#include <vector>
#include "Screen.cpp"
class Window_mrg{
    public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

    private:
     
    std::vector<Screen> screens{Screen(24,80,'')}
}