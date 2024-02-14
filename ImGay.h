#ifndef RAINBOW_UTILS_H
#define RAINBOW_UTILS_H

// Made by GrowHAX
// https://github.com/GrowHax

// make sure ImGui is included
#include <imgui/imgui.h>
#include <corecrt_math.h>
#include <string>

namespace ImGay {
	// RainbowColor is used for ImGui Styles
    // EXAMPLE: style.Colors[ImGuiCol_TabActive] = RainbowColor(3.0f, 0.0f);
    static ImVec4 Style(float frequency, float timeOffset, float alpha = 1.0f) {
        float r = sinf(frequency * ImGui::GetTime() + 0.0f + timeOffset) * 127.0f + 128.0f;
        float g = sinf(frequency * ImGui::GetTime() + 2.0f + timeOffset) * 127.0f + 128.0f;
        float b = sinf(frequency * ImGui::GetTime() + 4.0f + timeOffset) * 127.0f + 128.0f;

        return ImVec4(r / 255.0f, g / 255.0f, b / 255.0f, alpha);
    }

	// TextWrap is used for SPECIFIC strings 
	// EXAMPLE: ImGay::String("Hello World!", ImGay::Style(3.0f, 0.0f));
    static void String(const std::string& text, ImVec4 color) {
        ImGui::TextColored(color, "%s", text.c_str());
    }
}

#endif // RAINBOW_UTILS_H
