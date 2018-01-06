#include "GenerativeTreeSettingsManager.h"

#include "cinder/Log.h"

using namespace ci;
using namespace ci::app;
using namespace std;

namespace genApp {
	GenerativeTreeSettingsManager::GenerativeTreeSettingsManager() {
		addCommandLineParser("videos_preload", [this](string value) {
			mVideosPreload = value == "true";
		});
	}

	GenerativeTreeSettingsManager::~GenerativeTreeSettingsManager() {}

	void GenerativeTreeSettingsManager::parseJson(ci::JsonTree & json) {
		SettingsManager::parseJson(json);

		CI_LOG_D("Parsing Primary settings...");
		setFieldFromJsonIfExists(&mVideosPreload, "videos.preload");
		setFieldFromJsonIfExists(&mVideosAssetDir, "videos.assetDir");
	}
}