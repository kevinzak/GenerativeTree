#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/views/BaseView.h"
#include "bluecadet/views/ImageView.h"
#include "bluecadet/views/TouchView.h"

namespace genApp {

	typedef std::shared_ptr<class BaseLeaf> BaseLeafRef;

	class BaseLeaf : public bluecadet::views::BaseView {

	public:

		BaseLeaf();
		~BaseLeaf();

		void	setup();

	protected:
		// Functions
		void	setupParams();

		// Views


	};
}
