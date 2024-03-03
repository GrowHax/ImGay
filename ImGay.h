#ifndef RAINBOW_UTILS_H
#define RAINBOW_UTILS_H

// Made by GrowHAX
// https://github.com/GrowHax

// make sure ImGui is included
#include <imgui/imgui.h>
#include <corecrt_math.h>
#include <string>

bool Display_Popup = false;

namespace ImGay {
    static ImVec4 RainbowColor(const char* text, float alpha = 1.0f) {
        float Frequency = 0.1f;
        float TimeOffset = 0.0f;

        // const char* to std::string because of ImGui
        std::string str(text);

        float r = sinf(Frequency * ImGui::GetTime() + 0.0f + TimeOffset) * 127.0f + 128.0f;
        float g = sinf(Frequency * ImGui::GetTime() + 2.0f + TimeOffset) * 127.0f + 128.0f;
        float b = sinf(Frequency * ImGui::GetTime() + 4.0f + TimeOffset) * 127.0f + 128.0f;

        return ImVec4(r / 255.0f, g / 255.0f, b / 255.0f, alpha);
    }
	// RainbowColor is used for ImGui Styles
    // EXAMPLE: style.Colors[ImGuiCol_TabActive] = RainbowColor(3.0f, 0.0f);
    static ImVec4 Style(float Frequency, float TimeOffset, float alpha = 1.0f) {
        float r = sinf(Frequency * ImGui::GetTime() + 0.0f + TimeOffset) * 127.0f + 128.0f;
        float g = sinf(Frequency * ImGui::GetTime() + 2.0f + TimeOffset) * 127.0f + 128.0f;
        float b = sinf(Frequency * ImGui::GetTime() + 4.0f + TimeOffset) * 127.0f + 128.0f;

        return ImVec4(r / 255.0f, g / 255.0f, b / 255.0f, alpha);
    }

	// TextWrap is used for SPECIFIC strings 
	// EXAMPLE: ImGay::String("Hello World!", ImGay::Style(3.0f, 0.0f));
    static void String(const std::string& text, ImVec4 color) {
        ImGui::TextColored(color, "%s", text.c_str());
    }

    // MUST DECLARE THIS BEFORE ImGay::Popup("");
    // USAGE:
    //const uint64_t popupDuration = 2000; // set in milliseconds
    //uint64_t popupStartTime = 0;

    static void Popup(const char* messageText) {
        float WindowWidth = ImGui::GetWindowSize().x;
        float WindowHeight = ImGui::GetWindowSize().y;
        float WindowPosX = ImGui::GetWindowPos().x;
        float WindowPosY = ImGui::GetWindowPos().y;

        float PopupWidth = 180;
        float PopupHeight = 80;

        if (Display_Popup) {
            float popupPosX = WindowPosX + WindowWidth - PopupWidth;
            float popupPosY = WindowPosY + WindowHeight - PopupHeight;
            ImGui::SetNextWindowPos(ImVec2(popupPosX, popupPosY), ImGuiCond_Always);
            ImGui::SetNextWindowSize(ImVec2(PopupWidth, PopupHeight), ImGuiCond_Always);
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 1.0f, 0.0f, 1.0f)); // Text color

            if (ImGui::Begin("POPUP", &Display_Popup, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoFocusOnAppearing)) {
                ImGui::Text(messageText);
            }
            ImGui::End();

            ImGui::PopStyleVar();
            ImGui::PopStyleColor(1);
        }
        else {
            Display_Popup = false;
        }
    }

}

#endif // RAINBOW_UTILS_H
