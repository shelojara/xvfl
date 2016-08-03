#ifndef VFL_DEMUXCOMPONENT_HPP
#define VFL_DEMUXCOMPONENT_HPP


class Demux;


class DemuxComponent
{
protected:
    Demux * demux;

public:
    void setDemux(Demux * demux)
    {
        DemuxComponent::demux = demux;
    }
};


#endif //VFL_DEMUXCOMPONENT_HPP
