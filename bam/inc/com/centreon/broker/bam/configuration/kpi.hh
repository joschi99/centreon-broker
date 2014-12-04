/*
** Copyright 2014 Merethis
**
** This file is part of Centreon Broker.
**
** Centreon Broker is free software: you can redistribute it and/or
** modify it under the terms of the GNU General Public License version 2
** as published by the Free Software Foundation.
**
** Centreon Broker is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Centreon Broker. If not, see
** <http://www.gnu.org/licenses/>.
*/

#ifndef CCB_BAM_CONFIGURATION_KPI_HH
#  define CCB_BAM_CONFIGURATION_KPI_HH

#  include "com/centreon/broker/namespace.hh"
#  include "com/centreon/broker/bam/kpi_event.hh"

CCB_BEGIN()

namespace           bam {
  namespace         configuration {
    /**
     *  @class kpi kpi.hh "com/centreon/broker/bam/configuration/kpi.hh"
     *  @brief   Abstraction for representing a business interest in the
     *           form of a percentage value.
     *
     *  KPI configuration. It holds the rule of the KPI such as its
     *  impact, which service/BA it targets, ...
     */
    class           kpi {
    public:
                    kpi(
                      unsigned int id = 0,
                      short state_type = 0,
                      unsigned int host_id = 0,
                      unsigned int service_id = 0,
                      unsigned int ba_id = 0,
                      unsigned int indicator_ba = 0,
                      unsigned int meta_id = 0,
                      short status = 0,
                      short last_level = 0,
                      bool downtimed = false,
                      bool acknowledged = false,
                      bool ignoredowntime = false,
                      bool ignoreacknowledgement = false,
                      double warning = 0,
                      double critical = 0,
                      double unknown = 0);
                    kpi(kpi const& other);
                    ~kpi();
      kpi&          operator=(kpi const& other);
      bool          operator==(kpi const& other) const;
      bool          operator!=(kpi const& other) const;

      unsigned int  get_id() const;
      short         get_state_type() const;
      unsigned int  get_host_id() const;
      unsigned int  get_service_id() const;
      bool          is_service() const;
      bool          is_ba() const;
      bool          is_meta() const;
      unsigned int  get_ba_id() const;
      unsigned int  get_indicator_ba_id() const;
      unsigned int  get_meta_id() const;
      short         get_status() const;
      short         get_last_level() const;
      bool          is_downtimed() const;
      bool          is_acknowledged() const;
      bool          ignore_downtime() const;
      bool          ignore_acknowledgement() const;
      double        get_impact_warning() const;
      double        get_impact_critical() const;
      double        get_impact_unknown() const;
      bam::kpi_event const&
                    get_opened_event() const;

      void          set_id(unsigned int id);
      void          set_state_type(short state_type);
      void          set_host_id(unsigned int host_id);
      void          set_service_id(unsigned int service_id);
      void          set_ba_id(unsigned int ba_id);
      void          set_indicator_ba_id(unsigned int ba_id);
      void          set_meta_id(unsigned int meta_id);
      void          set_status(short status);
      void          set_last_level(short last_level);
      void          set_downtimed(bool downtimed);
      void          set_acknowledged(bool acknowledged);
      void          ignore_downtime(bool ignore);
      void          ignore_acknowledgement(bool ignore) ;
      void          set_impact_warning(double impact);
      void          set_impact_critical(double impact);
      void          set_impact_unknown(double impact);
      void          set_opened_event(bam::kpi_event const& kpi_event);

    private:
      unsigned int  _id;
      short         _state_type;
      unsigned int  _host_id;
      unsigned int  _service_id;
      unsigned int  _ba_id;
      unsigned int  _indicator_ba_id;
      unsigned int  _meta_id;
      short         _status;
      short         _last_level;
      bool          _downtimed;
      bool          _acknowledged;
      bool          _ignore_downtime;
      bool          _ignore_acknowledgement;
      double        _impact_warning;
      double        _impact_critical;
      double        _impact_unknown;
      bam::kpi_event
                    _event;
    };
  }
}

CCB_END()

#endif // CCB_BAM_CONFIGURATION_KPI_HH