#ifndef LLARP_HPP
#define LLARP_HPP

#include <crypto.h>
#include <llarp.h>
#include <threading.hpp>

#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct llarp_config;
struct llarp_config_iterator;

namespace llarp
{
  struct Context
  {
    ~Context();

    int num_nethreads   = 1;
    bool singleThreaded = false;
    std::unique_ptr< llarp::Crypto > crypto;
    llarp::Router *router    = nullptr;
    llarp_threadpool *worker = nullptr;
    llarp::Logic *logic      = nullptr;
    llarp_config *config     = nullptr;
    llarp_nodedb *nodedb     = nullptr;
    llarp_ev_loop *mainloop  = nullptr;
    std::string nodedb_dir;

    bool
    LoadConfig(const std::string &fname);

    void
    Close();

    int
    LoadDatabase();

    int
    IterateDatabase(struct llarp_nodedb_iter i);

    bool
    PutDatabase(struct llarp::RouterContact &rc);

    llarp::RouterContact *
    GetDatabase(const byte_t *pk);

    int
    Setup();

    int
    Run();

    void
    HandleSignal(int sig);

   private:
    bool
    Configure();

    void
    SigINT();

    bool
    ReloadConfig();

    static void
    iter_config(llarp_config_iterator *itr, const char *section,
                const char *key, const char *val);

    void
    progress();

    std::string configfile;
  };
}  // namespace llarp

#endif
