// ManagedREFPROP.h


#pragma warning(disable:4482)   //to prevent warning of using full qualified name, I need it because I duplicate the names in native and managed code



using namespace System;
using namespace System::Runtime::InteropServices;



namespace ManagedRefProp {

	public ref class WarningEventArgs : EventArgs
	{
	private:
		String^ _WarningMessage;
	public:
		WarningEventArgs(String^ warningMessage)
		{
			_WarningMessage = warningMessage;
		}

		property String^ WarningMessage
		{
			String^ get()
			{
				return _WarningMessage;
			}
		}


	};

	
}
