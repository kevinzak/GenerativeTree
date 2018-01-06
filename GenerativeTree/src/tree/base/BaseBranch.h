#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/views/BaseView.h"
#include "bluecadet/views/ImageView.h"
#include "bluecadet/views/TouchView.h"

#include "BaseLeaf.h"

namespace genApp {

	typedef std::shared_ptr<class BaseBranch> BaseBranchRef;

	class BaseBranch : public bluecadet::views::BaseView {

	public:

		BaseBranch();
		~BaseBranch();

		void	setup();

	protected:
		// Functions
		void	setupParams();
		void	generateLeaves(const int min, const int max);

		// Views
		// TODO: Add leaves
		BaseLeafRef	mLeaf;


	};
}
