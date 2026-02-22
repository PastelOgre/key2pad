#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <ViGEm/Client.h>
#include <string>
#include <vector>
#include <stdint.h>

HHOOK hook;
PVIGEM_CLIENT client;
PVIGEM_TARGET pad;
XUSB_REPORT report = {0};

uint32_t dpad_left=0;
uint32_t dpad_down=0;
uint32_t dpad_right=0;
uint32_t dpad_up=0;
uint32_t button_x=0;
uint32_t button_a=0;
uint32_t button_b=0;
uint32_t button_y=0;
uint32_t shoulder_left=0;
uint32_t shoulder_right=0;
uint32_t button_start=0;
uint32_t button_back=0;
uint32_t thumb_left=0;
uint32_t thumb_right=0;
uint32_t button_guide=0;


void ffstd_string_split(std::vector<std::string>* list, const std::string* str, char split_token)
{
	list->clear();
	int start_index = 0;
	int count = 0;
	unsigned i=0;
	for(;i<str->size();i++)
	{
		if((*str)[i] == split_token)
		{
			count = i-start_index;
			if(count > 0)
				list->push_back(str->substr(start_index, count));
			else
				list->push_back("");
			start_index = i+1;
		}
	}
	count = i-start_index;
	if(count > 0)
		list->push_back(str->substr(start_index));
	else
		list->push_back("");
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HC_ACTION)
    {
        KBDLLHOOKSTRUCT *kbd = (KBDLLHOOKSTRUCT*)lParam;

        if (wParam == WM_KEYDOWN)
        {
            if (kbd->vkCode == dpad_left)
            {
                report.wButtons |= XUSB_GAMEPAD_DPAD_LEFT;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == dpad_down)
            {
                report.wButtons |= XUSB_GAMEPAD_DPAD_DOWN;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == dpad_right)
            {
                report.wButtons |= XUSB_GAMEPAD_DPAD_RIGHT;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == dpad_up)
            {
                report.wButtons |= XUSB_GAMEPAD_DPAD_UP;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_x)
            {
                report.wButtons |= XUSB_GAMEPAD_X;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_a)
            {
                report.wButtons |= XUSB_GAMEPAD_A;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_b)
            {
                report.wButtons |= XUSB_GAMEPAD_B;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_y)
            {
                report.wButtons |= XUSB_GAMEPAD_Y;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == shoulder_left)
            {
                report.wButtons |= XUSB_GAMEPAD_LEFT_SHOULDER;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == shoulder_right)
            {
                report.wButtons |= XUSB_GAMEPAD_RIGHT_SHOULDER;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_start)
            {
                report.wButtons |= XUSB_GAMEPAD_START;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_back)
            {
                report.wButtons |= XUSB_GAMEPAD_BACK;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == thumb_left)
            {
                report.wButtons |= XUSB_GAMEPAD_LEFT_THUMB;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == thumb_right)
            {
                report.wButtons |= XUSB_GAMEPAD_RIGHT_THUMB;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_guide)
            {
                report.wButtons |= XUSB_GAMEPAD_GUIDE;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
        }
        else if(wParam == WM_KEYUP)
        {
            if(kbd->vkCode == dpad_left)
            {
                report.wButtons &= ~XUSB_GAMEPAD_DPAD_LEFT;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == dpad_down)
            {
                report.wButtons &= ~XUSB_GAMEPAD_DPAD_DOWN;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == dpad_right)
            {
                report.wButtons &= ~XUSB_GAMEPAD_DPAD_RIGHT;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == dpad_up)
            {
                report.wButtons &= ~XUSB_GAMEPAD_DPAD_UP;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_x)
            {
                report.wButtons &= ~XUSB_GAMEPAD_X;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_a)
            {
                report.wButtons &= ~XUSB_GAMEPAD_A;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_b)
            {
                report.wButtons &= ~XUSB_GAMEPAD_B;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == shoulder_left)
            {
                report.wButtons &= ~XUSB_GAMEPAD_LEFT_SHOULDER;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == shoulder_right)
            {
                report.wButtons &= ~XUSB_GAMEPAD_RIGHT_SHOULDER;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_y)
            {
                report.wButtons &= ~XUSB_GAMEPAD_Y;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_start)
            {
                report.wButtons &= ~XUSB_GAMEPAD_START;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_back)
            {
                report.wButtons &= ~XUSB_GAMEPAD_BACK;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == thumb_left)
            {
                report.wButtons &= ~XUSB_GAMEPAD_LEFT_THUMB;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == thumb_right)
            {
                report.wButtons &= ~XUSB_GAMEPAD_RIGHT_THUMB;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
            if(kbd->vkCode == button_guide)
            {
                report.wButtons &= ~XUSB_GAMEPAD_GUIDE;
                vigem_target_x360_update(client, pad, report);
                return 1; // block original key
            }
        }
    }
    return CallNextHookEx(hook, nCode, wParam, lParam);
}

int main ()
{
    FILE* fp = fopen("button_config.ini", "r");
    if(fp == NULL)
    {
        printf("Failed to open button_config.ini\n");
        return 1;
    }
    char line[256];
    uint8_t rebind_failed = 0;
    while(fgets(line, sizeof(line), fp))
    {
        std::string str(line);
        if(str.size() == 0)
            continue;
        if(str[0] == '#' || !isalpha(str[0]))
            continue;
        std::vector<std::string> tokens;
        ffstd_string_split(&tokens, &str, '=');
        if(tokens.size() != 2)
        {
            printf("Invalid line in button_config.ini: %s\n", line);
            printf("Expected format: key=value\n");
            printf("Rebind failed. Please fix the ini file and try again.\n");
            rebind_failed = 1;
            break;
        }
        std::string key = tokens[0];
        std::string value = tokens[1];
        if(value.size() > 0 && value[value.size()-1] == '\n')
            value.pop_back();
        if(value.size() == 0)
            continue;
        if(value.size() == 1)
        {
            if(isdigit(value[0]))
            {
                char vstr[64];
                sprintf(vstr, "0x%x", value[0]);
                value = vstr;
            }
            else
            {
                if(islower(value[0]))
                {
                    value[0] = toupper(value[0]);
                }
                if(isupper(value[0]))
                {
                    char vstr[64];
                    sprintf(vstr, "0x%x", value[0]);
                    value = vstr;
                }
            }
        }
        if(key == "dpad_left")
            dpad_left = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "dpad_down")
            dpad_down = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "dpad_right")
            dpad_right = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "dpad_up")
            dpad_up = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "button_x")
            button_x = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "button_a")
            button_a = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "button_b")
            button_b = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "button_y")
            button_y = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "shoulder_left")
            shoulder_left = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "shoulder_right")
            shoulder_right = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "button_start")
            button_start = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "button_back")
            button_back = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "thumb_left")
            thumb_left = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "thumb_right")
            thumb_right = (uint32_t)strtol(value.c_str(), NULL, 16);
        else if(key == "button_guide")
            button_guide = (uint32_t)strtol(value.c_str(), NULL, 16);
    }
    fclose(fp);
    client = vigem_alloc();
    if(vigem_connect(client) != VIGEM_ERROR_NONE)
    {
        printf("Failed to connect to ViGEmBus driver.\n");
        printf("Make sure you have the ViGEmBus driver installed and running.\n");
        printf("https://github.com/nefarius/ViGEmBus/releases\n");
        rebind_failed = 1;
    }
    pad = vigem_target_x360_alloc();
    if(vigem_target_add(client, pad) != VIGEM_ERROR_NONE)
    {
        printf("Failed to add virtual gamepad device.\n");
        printf("Make sure you have the ViGEmBus driver installed and running.\n");
        printf("https://github.com/nefarius/ViGEmBus/releases\n");
        rebind_failed = 1;
    }
    hook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);
    MSG msg;
    if(rebind_failed == 0)
        printf("Rebind successful. Press Ctrl+C or close window to exit.\n");
    else
        printf("Rebind failed. Press Ctrl+C or close window to exit.\n");
    while (GetMessage(&msg, NULL, 0, 0))
    {
        usleep(1);
    }

    return 0;
}