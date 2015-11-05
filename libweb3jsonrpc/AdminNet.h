#pragma once
#include "AdminNetFace.h"

namespace dev
{

class WebThreeNetworkFace;

namespace rpc
{

class SessionManager;

class AdminNet: public dev::rpc::AdminNetFace
{
public:
	AdminNet(WebThreeNetworkFace& _network, SessionManager& _sm);
	virtual bool admin_net_start(std::string const& _session) override;
	virtual bool admin_net_stop(std::string const& _session) override;
	virtual bool admin_net_connect(std::string const& _node, std::string const& _session) override;
	virtual Json::Value admin_net_peers(std::string const& _session) override;
	virtual Json::Value admin_net_nodeInfo(std::string const& _session) override;

private:
	WebThreeNetworkFace& m_network;
	SessionManager& m_sm;
};
	
}
}