{application,estatsd,
             [{description,"Stats aggregation service writing to a graphing system of your choice"},
              {vsn,"0.1.0"},
              {registered,[]},
              {applications,[kernel,stdlib,sasl,ssl,ibrowse]},
              {mod,{estatsd_app,[]}},
              {modules,[estatsd,estatsd_app,estatsd_server,estatsd_sup,
                        estatsd_udp,estatsda_adapter,estatsda_librato,
                        estatsda_logger]}]}.
