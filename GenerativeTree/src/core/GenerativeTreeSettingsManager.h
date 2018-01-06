#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/core/SettingsManager.h"

namespace genApp {
	typedef std::shared_ptr<class GenerativeTreeSettingsManager> GenerativeTreeSettingsManagerRef;
	class GenerativeTreeSettingsManager : public bluecadet::core::SettingsManager {

	public:

		static GenerativeTreeSettingsManagerRef getInstance() {
			static GenerativeTreeSettingsManagerRef instance = nullptr;
			if (!instance) {
				instance = GenerativeTreeSettingsManagerRef(new GenerativeTreeSettingsManager());
			}
			return instance;
		}

		GenerativeTreeSettingsManager();
		~GenerativeTreeSettingsManager();

		void parseJson(ci::JsonTree & json) override;

		bool			mVideosPreload = true;
		std::string		mVideosAssetDir = "";
	};

}