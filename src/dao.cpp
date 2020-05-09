#include <dao.hpp>
ACTION dao::setproxy(name proxy)
{
   require_auth(get_self());
   configs cfg = _configs.get();
   cfg.vote_proxy = proxy;
   _configs.set(cfg, _self);
}

ACTION dao::setoracle(name oracle)
{
   require_auth(get_self());
   configs cfg = _configs.get();
   cfg.price_oracle = oracle;
   _configs.set(cfg, _self);
}

ACTION dao::setmid(uint64_t mid)
{
   require_auth(get_self());
   configs cfg = _configs.get();
   cfg.market_id = mid;
   _configs.set(cfg, _self);
}

ACTION dao::setperiod(uint64_t period)
{
   require_auth(get_self());
   configs cfg = _configs.get();
   cfg.price_period = period;
   _configs.set(cfg, _self);
}

ACTION dao::setlower(uint64_t lower)
{
   require_auth(get_self());
   configs cfg = _configs.get();
   cfg.price_lower_bound = lower;
   _configs.set(cfg, _self);
}

ACTION dao::setupper(uint64_t upper)
{
   require_auth(get_self());
   configs cfg = _configs.get();
   cfg.price_upper_bound = upper;
   _configs.set(cfg, _self);
}

ACTION dao::setratio(uint64_t ratio)
{
   require_auth(get_self());
   configs cfg = _configs.get();
   cfg.minimum_collateral_ratio = ratio;
   _configs.set(cfg, _self);
}

ACTION dao::setmindep(uint64_t mindep)
{
   require_auth(get_self());
   configs cfg = _configs.get();
   cfg.minimum_deposit = mindep;
   _configs.set(cfg, _self);
}

ACTION dao::setfee(uint64_t fee)
{
   require_auth(get_self());
   configs cfg = _configs.get();
   cfg.mint_fee = fee;
   _configs.set(cfg, _self);
}