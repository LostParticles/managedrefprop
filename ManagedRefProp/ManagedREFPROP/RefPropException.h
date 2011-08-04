#pragma once

namespace ManagedRefProp
{
	public ref class RefPropException : public System::Exception
	{
	public:
		RefPropException(System::String^ message);
	};
}