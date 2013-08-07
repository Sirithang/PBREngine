#pragma once

#include "array.h"

namespace sigurd
{
	template<class T>
	void objCreated(T& obj)
	{
		//if this is triggered by compilation
		//mean you need to overload this fonction with one of your object stocked into the ObjectManager
		int fallthrought[0];
	}

	template<class T>
	void objDeleted(T& obj)
	{
		int fallthrought[0];
	}

	///=======================================

	struct ManagedObject
	{
		//this is the id in the corresponding ObjectManager
		uint32_t _managedID;
	};

	//========================================

	/**
	* This allow to manage object in a flat array (cache friendly)
	* object must containe a _id member(subclass from ManagedObject is easier)
	* and must define a fonction objCreated(T) and objRemoved(T)
	*/
	template<class T, int InitialSize>
	class ObjectManager
	{
		foundation::Array<T> _objectArray;
		//this is the max array number not yet associated with something
		int _top;

		foundation::Array<uint32_t> _freeIDS; // free id in the array

		static ObjectManager instance;

	protected:
		ObjectManager()
			: _objectArray(foundation::memory_globals::default_allocator())
		{
			foundation::array::reserve(_objectArray, InitialSize);
			_top = 0;
			
			foundation::array::reserve(_freeIDS, 64);
		}

		//-----------------------------------------------------------
	public:
		int createObject()
		{
			uint32_t val = 0;
			if(foundation::array::any(_freeIDS))
			{
				val = foundation::array::back(_freeIDS);
				foundation::array::pop_back(_freeIDS);
			}
			else
			{
				val = _top;
				_top++;
			}
			
			_objectArray[val]._managedID = val;
			objCreated(_objectArray[val]);
			return val;
		}

		//-----------------------------------------------------------

		int deleteObject(uint32_t id)
		{
			objDeleted(_objectArray[id]);

			foundation::array::push_back(_freeIDS, id);
		}

	};

	template<class T, int InitialSize>
	ObjectManager<T,InitialSize> ObjectManager<T,InitialSize>::instance;
}