#include <eosio/eosio.hpp>
#include <eosio/singleton.hpp>
using namespace eosio;

CONTRACT dao : public contract
{
public:
   using contract::contract;

   dao(name receiver, name code, datastream<const char *> ds)
       : contract(receiver, code, ds),
         _configs(_self, _self.value)
   {

      if (!_configs.exists())
      {
         _configs.get_or_create(_self,
                                configs{
                                    .price_oracle = name("jinoracle111"),
                                    .vote_proxy = name("jinbank.bp"),
                                    .price_period = 3600,
                                    .price_lower_bound = 20000,
                                    .price_upper_bound = 50000,
                                    .minimum_collateral_ratio = 300,
                                    .mint_fee = 3});
      }
   }

   ACTION setproxy(name proxy);
   ACTION setoracle(name oracle);
   ACTION setperiod(uint64_t period);
   ACTION setlower(uint64_t lower);
   ACTION setupper(uint64_t upper);
   ACTION setratio(uint64_t ratio);
   ACTION setfee(uint64_t fee);

   using setproxy_action = action_wrapper<"setproxy"_n, &dao::setproxy>;
   using setoracle_action = action_wrapper<"setoracle"_n, &dao::setoracle>;
   using setperiod_action = action_wrapper<"setperiod"_n, &dao::setperiod>;
   using setlower_action = action_wrapper<"hi"_n, &dao::setlower>;
   using setupper_action = action_wrapper<"setupper"_n, &dao::setupper>;
   using setratio_action = action_wrapper<"setratio"_n, &dao::setratio>;
   using setfee_action = action_wrapper<"setfee"_n, &dao::setfee>;

private:
   TABLE configs
   {
      name vote_proxy;
      name price_oracle;
      uint64_t price_period;
      uint64_t price_lower_bound;
      uint64_t price_upper_bound;
      uint64_t minimum_collateral_ratio;
      uint64_t mint_fee;

      EOSLIB_SERIALIZE(configs, (vote_proxy)(price_oracle)(price_period)(price_lower_bound)(price_upper_bound)(minimum_collateral_ratio)(mint_fee))
   };

   typedef singleton<"configs"_n, configs> configs_index;
   configs_index _configs;
};