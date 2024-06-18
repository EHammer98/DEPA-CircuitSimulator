#pragma once

template <typename ID, typename Class>
void
ComponentFactory<ID, Class>::assign(const ID& cID, const Class* pClass)
{
    static  FactoryMap& cMap = getMap();

    assert(cMap.find(cID) == cMap.end());

    cMap[cID] = pClass;
}

template <typename ID, typename Class>
Class*
ComponentFactory<ID, Class>::create(const ID& cID)
{
    static  FactoryMap& cMap = getMap();
    typename FactoryMap::iterator   iFind = cMap.find(cID);

    if (iFind == cMap.end())
        return nullptr;
    else
        return iFind->second->clone();
}

template <typename ID, typename Class>
typename ComponentFactory<ID, Class>::FactoryMap&
ComponentFactory<ID, Class>::getMap()
{
    static  FactoryMap  cMap;
    return cMap;
}
