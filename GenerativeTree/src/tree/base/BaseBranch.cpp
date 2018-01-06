#include "BaseBranch.h"

#include "cinder/Log.h"

#include "bluecadet/utils/ImageManager.h"
#include "bluecadet/core/SettingsManager.h"
#include "bluecadet/core/ScreenLayout.h"

#include "bluecadet/views/AnimatedView.h"
#include "bluecadet/views/TextView.h"

#include "../../core/GenerativeTreeSettingsManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bluecadet;
using namespace bluecadet::core;
using namespace bluecadet::views;
using namespace bluecadet::utils;

namespace genApp {

	BaseBranch::BaseBranch() : BaseView() {
	}

	BaseBranch::~BaseBranch() {
	}

	void BaseBranch::setup() {
		// Configure canvas
		setSize(vec2(50, 400));
		setBackgroundColor(Color::gray(0.2f));

		// Setup Views
		mLeaf = make_shared<BaseLeaf>();
		mLeaf->setup();
		mLeaf->setPosition(vec2(0, getHeight()));
		mLeaf->setRotation(0.2f);
		//addChild(mLeaf);

		generateLeaves(10, 10);
	}

	//==================================================
	// Generate Functions
	// 

	//float r = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));

	void BaseBranch::generateLeaves(const int min, const int max) {
		int numOfLeaves = (rand() % max) + min;
		for (int i = 0; i < numOfLeaves; i++) {
			BaseLeafRef newLeaf = make_shared<BaseLeaf>();
			newLeaf->setup();
			float xPos = -mLeaf->getWidth() + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (getWidth() - -mLeaf->getWidth())));
			float yPos = (getHeight() * 0.6) + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (getHeight() - (getHeight() * 0.6))));
			newLeaf->setPosition(vec2(xPos, yPos));
			addChild(newLeaf);
		}
	}

	//==================================================
	// Setup helpers
	// 

	void BaseBranch::setupParams() {

	}

}
