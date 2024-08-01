#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameManager.hpp>

class $modify(PlayLayer) {
	void updateAttempts() {
		PlayLayer::updateAttempts();

		bool useTotal = geode::Mod::get()->getSettingValue<bool>("useTotal");
		std::string customString = geode::Mod::get()->getSettingValue<std::string>("text");

		auto attemptLabel = this->m_attemptLabel;
		if (attemptLabel) {
			auto level = this->m_level;
			
			int attemptsToShow = useTotal ? level->m_attempts + 1 : this->m_attempts;

			size_t pos = customString.find("#");
			if (pos != std::string::npos) {
				customString.replace(pos, 1, std::to_string(attemptsToShow));
			}
			
			attemptLabel->setString(customString.c_str());
		}
	}
};