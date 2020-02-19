#ifndef _H_KEYMAP_
#define _H_KEYMAP_

#include <map>
#include <linux/input.h>

struct Keymap
{
    const int KEY_SUPER = 458979;
    const int KEYPRESS = 0;
    const int KEYRELEASE = 1;
    const int KEYDOWN = 2;
    
    const std::map<char,int> keyChar = {
    {'a', 458756}, {'b', 458757}, {'c', 458758}, {'d', 458759}, {'e', 458760},
    {'f', 458761}, {'g', 458762}, {'h', 458763}, {'i', 458764}, {'j', 458765},
    {'k', 458766}, {'l', 458767}, {'m', 458768}, {'n', 458769}, {'o', 458770},
    {'p', 458771}, {'q', 458772}, {'r', 458773}, {'s', 458774}, {'t', 458775},
    {'u', 458776}, {'v', 458777}, {'w', 458778}, {'x', 458779}, {'y', 458780},
    {'z', 458781},
    {'1', 458782}, {'2', 458783}, {'3', 458784}, {'4', 458785}, {'5', 458786},
    {'6', 458787}, {'7', 458788}, {'8', 458789}, {'9', 458790}, {'0', 458791},

    {'\n', 458792}, {'\27', 458793}, {'\b', 458794}, {'\t', 458795},
    {' ', 458796}, {'-', 458797}, {'=', 458798}, {'[', 458799},
    {']', 458800}, {'\\', 458801},               {';', 458803},
    {'\'', 458804}, {'`', 458805}, {',', 458806},{'.', 458807},
    {'/', 458808}
    };

    const std::map<int,int> keyCode = {
    {0, KEYPRESS}, {1, KEYRELEASE}, {2, KEYDOWN},  
    {458756, KEY_A}, {458757, KEY_B}, {458758, KEY_C}, {458759, KEY_D},
    {458760, KEY_E}, {458761, KEY_F}, {458762, KEY_G}, {458763, KEY_H},
    {458764, KEY_I}, {458765, KEY_J}, {458766, KEY_K}, {458767, KEY_L}, 
    {458768, KEY_M}, {458769, KEY_N}, {458770, KEY_O}, {458771, KEY_P}, 
    {458772, KEY_Q}, {458773, KEY_R}, {458774, KEY_S}, {458775, KEY_T},
    {458776, KEY_U}, {458777, KEY_V}, {458778, KEY_W}, {458779, KEY_X},
    {458780, KEY_Y}, {458781, KEY_Z},

    {458782, KEY_1}, {458783, KEY_2}, {458784, KEY_3}, {458785, KEY_4},
    {458786, KEY_5}, {458787, KEY_6}, {458788, KEY_7}, {458789, KEY_8},
    {458790, KEY_9}, {458791, KEY_0},

    {458792, KEY_ENTER}, {458793, KEY_ESC}, {458794, KEY_BACKSPACE},
    {458795, KEY_TAB}, {458796, KEY_SPACE}, {458797, KEY_MINUS},
    {458798, KEY_EQUAL}, {458799, KEY_LEFTBRACE}, {458800, KEY_RIGHTBRACE},
    {458801, KEY_BACKSLASH}, {458803, KEY_SEMICOLON}, {458804, KEY_APOSTROPHE},
    {458805, KEY_GRAVE}, {458806, KEY_COMMA},{458807, KEY_DOT},
    {458808, KEY_SLASH}, {458809, KEY_CAPSLOCK},

    {458810, KEY_F1}, {458811, KEY_F2}, {458812, KEY_F3}, {458813, KEY_F4},
    {458814, KEY_F5}, {458815, KEY_F6}, {458816, KEY_F7}, {458817, KEY_F8},
    {458818, KEY_F9}, {458819, KEY_F10},{458820, KEY_F11},{458821, KEY_F12},

    {458822, KEY_PRINT}, {458822, KEY_SCREENLOCK}, {458824, KEY_PAUSE},
    {458825, KEY_INSERT},{458826, KEY_HOME},
    {458827, KEY_PAGEUP}, {458828, KEY_DELETE}, {458830, KEY_PAGEDOWN},

    {458831, KEY_RIGHT}, {458832, KEY_LEFT}, {458833, KEY_DOWN},
    {458834, KEY_UP},

    {458835, KEY_NUMLOCK},

    {458836, KEY_KPSLASH}, {458837, KEY_KPASTERISK}, {458838, KEY_KPMINUS},
    {458839, KEY_KPPLUS}, {458840, KEY_KPENTER},

    {458841, KEY_KP1}, {458842, KEY_KP2}, {458843, KEY_KP3}, {458844, KEY_KP4},
    {458845, KEY_KP5}, {458846, KEY_KP6}, {458847, KEY_KP7}, {458848, KEY_KP8},
    {458849, KEY_KP9}, {458850, KEY_KP0},

    {458851, KEY_KPDOT},

    {458853, KEY_MENU},

    {458976, KEY_LEFTCTRL}, {458977, KEY_LEFTSHIFT}, {458978, KEY_LEFTALT},
    {458979, KEY_SUPER},
    {458980, KEY_RIGHTCTRL}, {458981, KEY_RIGHTSHIFT}, {458982, KEY_RIGHTALT},


    };
};





#endif