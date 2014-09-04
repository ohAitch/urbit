/* j/6/find.c
**
** This file is in the public domain.
*/
#include "all.h"


/* logic
*/
  static u2_noun
  _fino_in(
           u2_noun van,
           u2_noun sut,
           u2_noun dep,
           u2_noun way,
           u2_noun cog,
           u2_noun gil)
  {
    u2_noun p_sut, q_sut;

    if ( u2_yes == u2ud(sut) ) {
      return u2nc(u2k(dep), u2_nul);
    }
    else switch ( u2h(sut) ) {
      default: return u2nc(u2k(dep), u2_nul);

      case c3__bull: {
        if ( (u2_no == u2_cr_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_cm_bail(c3__fail);
        }
        else {
          if ( u2_no == u2_cr_sing(cog, u2h(p_sut)) ) {
            return _fino_in
              (van, q_sut, dep, way, cog, gil);
          }
          else {
            if ( 0 == dep ) {
              return u2nc
                (0,
                        u2nt(
                              u2_nul,
                              1,
                              u2nt(2, u2k(p_sut),
                                              u2k(q_sut))));
            } else {
              return _fino_in
                (
                 van, q_sut, u2_cqa_dec(dep), way, cog, gil);
            }
          }
        }
      }
      case c3__cell: {
        if ( (u2_no == u2_cr_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_cm_bail(c3__fail);
        } else {
          u2_noun taf = _fino_in(van, p_sut, dep, way, cog, gil);
          u2_noun p_taf = u2h(taf);
          u2_noun q_taf = u2t(taf);
          u2_noun ret;

          if ( u2_nul == q_taf ) {
            u2_noun bov = _fino_in(van, q_sut, p_taf, way, cog, gil);
            u2_noun p_bov = u2h(bov);
            u2_noun q_bov = u2t(bov);

            if ( u2_nul == q_bov ) {
              ret = u2k(bov);
            }
            else {
              u2_noun puq_bov, quq_bov;

              u2_cr_mean(q_bov, 6, &puq_bov, 7, &quq_bov, 0);
              ret = u2nq
                (u2k(p_bov),
                        u2_nul,
                        u2_cqc_peg(3, puq_bov),
                        u2k(quq_bov));
            }
            u2z(bov);
          }
          else {
            u2_noun puq_taf, quq_taf;

            u2_cr_mean(q_taf, 6, &puq_taf, 7, &quq_taf, 0);
            ret = u2nq
              (u2k(p_taf),
                      u2_nul,
                      u2_cqc_peg(2, puq_taf),
                      u2k(quq_taf));
          }
          u2z(taf);
          return ret;
        }
      }
      case c3__core: {
        u2_noun pq_sut, qq_sut, rq_sut;
        u2_noun prq_sut, qrq_sut;

        if ( (u2_no == u2_cr_trel(sut, 0, &p_sut, &q_sut)) ||
             (u2_no == u2_cr_trel(q_sut, &pq_sut, &qq_sut, &rq_sut)) ||
             (u2_no == u2_cr_cell(rq_sut, &prq_sut, &qrq_sut)) )
        {
          return u2_cm_bail(c3__fail);
        } else {
          u2_noun zem = u2_cqf_look(cog, qrq_sut);

          if ( (u2_nul != zem) && (0 != dep) ) {
            u2_noun ped;

            ped = u2_cqa_dec(dep);
            u2z(dep); dep = ped;

            u2z(zem);
            zem = u2_nul;
          }

          if ( u2_nul == zem ) {
            u2_noun taf = _fino_in(van, p_sut, dep, way, cog, gil);
            u2_noun p_taf = u2h(taf);
            u2_noun q_taf = u2t(taf);

            if ( u2_nul == q_taf ) {
              u2z(taf);
              return u2nc(u2k(dep), u2_nul);
            }
            else {
              u2_noun puq_taf, quq_taf;
              u2_noun pro;

              u2_cr_mean(q_taf, 6, &puq_taf, 7, &quq_taf, 0);

              if ( u2_no == u2_cqfu_park
                    (van, sut, way, puq_taf) )
              {
                u2_noun weh = u2_cqfu_shep
                  (van, "way", 'a', u2k(way));
                u2_noun waz = u2_cqfu_shep
                  (van, "axis", 'd', u2k(puq_taf));

                u2_ct_push(u2nc(c3__mean, weh));
                u2_ct_push(u2nc(c3__mean, waz));
                return u2_cm_error("find-park");
              }
              else {
                pro = u2nq
                  (u2k(p_taf),
                          u2_nul,
                          u2_cqc_peg(3, puq_taf),
                          u2k(quq_taf));

                u2z(taf);
                return pro;
              }
            }
          }
          else {
            u2_noun u_zem = u2t(zem);
            u2_noun pu_zem = u2h(u_zem);
            u2_noun qu_zem = u2t(u_zem);
            u2_noun mut;
            u2_noun pro;

            mut = u2nt(c3__core,
                               u2k(p_sut),
                               u2nt(c3__gold,
                                            u2k(qq_sut),
                                            u2k(rq_sut)));

            pro = u2nc
              (
               0,
               u2nq(
                     u2_nul,
                     1,
                     1,
                     u2nc
                       (u2_cqc_peg(2, pu_zem),
                               u2nc(
                                     u2nc(mut, u2k(qu_zem)),
                                     u2_nul))));
            u2z(zem);
            return pro;
          }
        }
      }
      case c3__face: {
        if ( (u2_no == u2_cr_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_cm_bail(c3__fail);
        } else {
          if ( u2_no == u2_cr_sing(cog, p_sut) ) {
            return u2nc(u2k(dep), u2_nul);
          } else {
            if ( 0 == dep ) {
              return u2nc
                (0,
                        u2nq(u2_nul, 1, 0, u2k(q_sut)));
            } else {
              return u2nc
                (u2_cqa_dec(dep), u2_nul);
            }
          }
        }
      }
      case c3__cube: {
        u2_noun fop = u2_cqfu_repo(van, sut);
        u2_noun pro = _fino_in(van, fop, dep, way, cog, gil);

        u2z(fop);
        return pro;
      }
      case c3__fork: {
        if ( (u2_no == u2_cr_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_cm_bail(c3__fail);
        }

        if ( (u2_yes == u2_cqdi_has(gil, q_sut)) ) {
          return _fino_in(van, p_sut, dep, way, cog, gil);
        }
        else if ( (u2_yes == u2_cqdi_has(gil, p_sut)) ) {
          return _fino_in(van, q_sut, dep, way, cog, gil);
        }
        else {
          u2_noun hax = _fino_in(van, p_sut, dep, way, cog, gil);
          u2_noun yor = _fino_in(van, q_sut, dep, way, cog, gil);
          u2_noun p_hax = u2h(hax);
          u2_noun p_yor = u2h(yor);
          u2_noun q_hax = u2t(hax);
          u2_noun q_yor = u2t(yor);
          u2_noun puq_hax, quq_hax;
          u2_noun puq_yor, quq_yor;
          u2_noun ret;

          if ( u2_nul != q_hax ) {
            u2_cr_mean(q_hax, 6, &puq_hax, 7, &quq_hax, 0);
          }
          if ( u2_nul != q_yor ) {
            u2_cr_mean(q_yor, 6, &puq_yor, 7, &quq_yor, 0);
          }

          if ( u2_yes == u2_cr_sing(hax, yor) ) {
            ret = u2k(hax);
          }
          else {
            if ( (u2_no == u2_cr_sing(p_hax, p_yor)) ||
                 ((u2_nul == q_hax) || (u2_nul == q_yor)) ||
                 (u2_no == u2_cr_sing(puq_hax, puq_yor)) ||
                 (u2_no == u2_cr_sing(u2h(quq_hax), u2h(quq_yor))) )
            {
              return u2_cm_error("find-fork");
            }
            switch ( u2h(quq_hax) ) {
              case 0: {
                u2_noun pquq_hax = u2t(quq_hax);
                u2_noun pquq_yor = u2t(quq_yor);

                ret = u2nc
                  (
                   u2k(p_hax),
                   u2nq
                    (
                     u2_nul,
                     u2k(puq_hax),
                     0,
                     u2_cqf_fork(pquq_hax, pquq_yor)));
                break;
              }
              case 1: {
                u2_noun pquq_hax, qquq_hax, pquq_yor, qquq_yor;

                u2_cx_cell(u2t(quq_hax), &pquq_hax, &qquq_hax);
                u2_cx_cell(u2t(quq_yor), &pquq_yor, &qquq_yor);

                if ( u2_no == u2_cr_sing(pquq_hax, pquq_yor) ) {
                  return u2_cm_error("find-fork");
                } else {
                  ret = u2nc
                    (
                     u2k(p_hax),
                     u2nq
                      (u2_nul,
                              u2k(puq_hax),
                              1,
                              u2nc
                                (u2k(pquq_hax),
                                        u2_cqb_weld
                                          (qquq_hax, qquq_yor))));
                  break;
                }
              }
              case 2: {
                u2_noun pquq_hax, qquq_hax, pquq_yor, qquq_yor;
                u2_noun ppquq_hax, qpquq_hax, rpquq_hax, spquq_hax;
                u2_noun ppquq_yor, qpquq_yor, rpquq_yor, spquq_yor;

                u2_cx_cell(u2t(quq_hax), &pquq_hax, &qquq_hax);
                u2_cx_cell(u2t(quq_yor), &pquq_yor, &qquq_yor);
                u2_cx_qual(
                           pquq_hax,
                           &ppquq_hax, &qpquq_hax, &rpquq_hax, &spquq_hax);
                u2_cx_qual(
                           pquq_yor,
                           &ppquq_yor, &qpquq_yor, &rpquq_yor, &spquq_yor);

                if ( (u2_no == u2_cr_sing(ppquq_hax, ppquq_yor)) ||
                     (u2_no == u2_cr_sing(qpquq_hax, qpquq_yor)) ||
                     (u2_no == u2_cr_sing(rpquq_hax, rpquq_yor)) )
                {
                  return u2_cm_error("find-fork");
                }
                else {
                  ret = u2nc
                    (
                     u2k(p_hax),
                     u2nq
                      (
                       u2_nul,
                       u2k(puq_hax),
                       2,
                       u2nc(
                             u2nq(
                                   u2k(ppquq_hax),
                                   u2k(qpquq_hax),
                                   u2k(rpquq_hax),
                                   u2_cqf_fork(
                                                     spquq_hax,
                                                     spquq_yor)),
                             u2_cqf_fork(qquq_hax, qquq_yor))));
                  break;
                }
              }
            }
          }
          u2z(yor);
          u2z(hax);

          return ret;
        }
      }
      case c3__hold: p_sut = u2t(sut);
      {
        if ( (u2_yes == u2_cqdi_has(gil, sut)) ) {
          return u2nc(u2k(dep), u2_nul);
        }
        else {
          u2_noun zoc = u2_cqdi_put(gil, sut);
          u2_noun fop = u2_cqfu_repo(van, sut);
          u2_noun pro = _fino_in(van, fop, dep, way, cog, zoc);

          u2z(fop);
          u2z(zoc);

          return pro;
        }
      }
    }
  }

  static u2_noun
  _find_in(
           u2_noun van,
           u2_noun sut,
           u2_noun dep,
           u2_noun way,
           u2_noun cog,
           u2_noun gil)
  {
    u2_noun p_sut, q_sut, pp_sut, qp_sut, rp_sut, sp_sut;

    if ( u2_yes == u2ud(sut) ) {
      return u2nc(u2k(dep), u2_nul);
    }
    else switch ( u2h(sut) ) {
      default: return u2nc(u2k(dep), u2_nul);

      case c3__bull: {
        if ( (u2_no == u2_cr_trel(sut, 0, &p_sut, &q_sut)) ||
             (u2_no == u2_cr_qual(p_sut, &pp_sut, &qp_sut, &rp_sut, &sp_sut)) )
        {
          return u2_cm_bail(c3__fail);
        }
        else {
          if ( u2_no == u2_cr_sing(cog, pp_sut) ) {
            return _find_in
              (van, q_sut, dep, way, cog, gil);
          }
          else {
            if ( 0 == dep ) {
              return u2nc
                (0,
                        u2nq(
                              u2_nul,
                              u2k(rp_sut),
                              u2_yes,
                              u2k(sp_sut)));
            } else {
              return _find_in
                (
                 van, q_sut, u2_cqa_dec(dep), way, cog, gil);
              return u2nc
                (u2_cqa_dec(dep), u2_nul);
            }
          }
        }
      }
      case c3__cell: {
        if ( (u2_no == u2_cr_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_cm_bail(c3__fail);
        } else {
          u2_noun taf = _find_in(van, p_sut, dep, way, cog, gil);
          u2_noun p_taf = u2h(taf);
          u2_noun q_taf = u2t(taf);
          u2_noun ret;

          if ( u2_nul == q_taf ) {
            u2_noun bov = _find_in(van, q_sut, p_taf, way, cog, gil);
            u2_noun p_bov = u2h(bov);
            u2_noun q_bov = u2t(bov);

            if ( u2_nul == q_bov ) {
              ret = u2k(bov);
            }
            else {
              u2_noun puq_bov, quq_bov;

              u2_cr_mean(q_bov, 6, &puq_bov, 7, &quq_bov, 0);
              ret = u2nq
                (u2k(p_bov),
                        u2_nul,
                        u2_cqc_peg(3, puq_bov),
                        u2k(quq_bov));
            }
            u2z(bov);
          }
          else {
            u2_noun puq_taf, quq_taf;

            u2_cr_mean(q_taf, 6, &puq_taf, 7, &quq_taf, 0);
            ret = u2nq
              (u2k(p_taf),
                      u2_nul,
                      u2_cqc_peg(2, puq_taf),
                      u2k(quq_taf));
          }
          u2z(taf);
          return ret;
        }
      }
      case c3__core: {
        u2_noun pq_sut, qq_sut, rq_sut;
        u2_noun prq_sut, qrq_sut;

        if ( (u2_no == u2_cr_trel(sut, 0, &p_sut, &q_sut)) ||
             (u2_no == u2_cr_trel(q_sut, &pq_sut, &qq_sut, &rq_sut)) ||
             (u2_no == u2_cr_cell(rq_sut, &prq_sut, &qrq_sut)) )
        {
          return u2_cm_bail(c3__fail);
        } else {
          u2_noun zem = u2_cqf_look(cog, qrq_sut);

          if ( (u2_nul != zem) && (0 != dep) ) {
            u2_noun ped;

            ped = u2_cqa_dec(dep);
            u2z(dep); dep = ped;

            u2z(zem);
            zem = u2_nul;
          }

          if ( u2_nul == zem ) {
            u2_noun taf = _find_in(van, p_sut, dep, way, cog, gil);
            u2_noun p_taf = u2h(taf);
            u2_noun q_taf = u2t(taf);

            if ( u2_nul == q_taf ) {
              u2z(taf);
              return u2nc(u2k(dep), u2_nul);
            }
            else {
              u2_noun puq_taf, quq_taf;
              u2_noun pro;

              u2_cr_mean(q_taf, 6, &puq_taf, 7, &quq_taf, 0);

              if ( u2_no == u2_cqfu_park
                    (van, sut, way, puq_taf) )
              {
                u2_noun weh = u2_cqfu_shep
                  (van, "way", 'a', u2k(way));
                u2_noun waz = u2_cqfu_shep
                  (van, "axis", 'd', u2k(puq_taf));

                u2_ct_push(u2nc(c3__mean, weh));
                u2_ct_push(u2nc(c3__mean, waz));
                return u2_cm_error("find-park");
              }
              else {
                pro = u2nq
                  (u2k(p_taf),
                          u2_nul,
                          u2_cqc_peg(3, puq_taf),
                          u2k(quq_taf));

                u2z(taf);
                return pro;
              }
            }
          }
          else {
            u2_noun u_zem = u2t(zem);
            u2_noun pu_zem = u2h(u_zem);
            u2_noun qu_zem = u2t(u_zem);
            u2_noun mut;
            u2_noun pro;

            mut = u2nt(c3__core,
                               u2k(p_sut),
                               u2nt(c3__gold,
                                            u2k(qq_sut),
                                            u2k(rq_sut)));

            pro = u2nc
              (
               0,
               u2nq(
                     u2_nul,
                     1,
                     u2_no,
                     u2nc
                       (u2_cqc_peg(2, pu_zem),
                               u2nc(
                                     u2nc(mut, u2k(qu_zem)),
                                     u2_nul))));
            u2z(zem);
            return pro;
          }
        }
      }
      case c3__face: {
        if ( (u2_no == u2_cr_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_cm_bail(c3__fail);
        } else {
          if ( u2_no == u2_cr_sing(cog, p_sut) ) {
            return u2nc(u2k(dep), u2_nul);
          } else {
            if ( 0 == dep ) {
              return u2nc
                (0,
                        u2nq(u2_nul, 1, u2_yes, u2k(q_sut)));
            } else {
              return u2nc
                (u2_cqa_dec(dep), u2_nul);
            }
          }
        }
      }
      case c3__cube: {
        u2_noun fop = u2_cqfu_repo(van, sut);
        u2_noun pro = _find_in(van, fop, dep, way, cog, gil);

        u2z(fop);
        return pro;
      }
      case c3__fork: {
        if ( (u2_no == u2_cr_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_cm_bail(c3__fail);
        }

        if ( (u2_yes == u2_cqdi_has(gil, q_sut)) ) {
          return _find_in(van, p_sut, dep, way, cog, gil);
        }
        else if ( (u2_yes == u2_cqdi_has(gil, p_sut)) ) {
          return _find_in(van, q_sut, dep, way, cog, gil);
        }
        else {
          u2_noun hax = _find_in(van, p_sut, dep, way, cog, gil);
          u2_noun yor = _find_in(van, q_sut, dep, way, cog, gil);
          u2_noun p_hax = u2h(hax);
          u2_noun p_yor = u2h(yor);
          u2_noun q_hax = u2t(hax);
          u2_noun q_yor = u2t(yor);
          u2_noun puq_hax, quq_hax;
          u2_noun puq_yor, quq_yor;
          u2_noun ret;

          if ( u2_nul != q_hax ) {
            u2_cr_mean(q_hax, 6, &puq_hax, 7, &quq_hax, 0);
          }
          if ( u2_nul != q_yor ) {
            u2_cr_mean(q_yor, 6, &puq_yor, 7, &quq_yor, 0);
          }

          if ( u2_yes == u2_cr_sing(hax, yor) ) {
            ret = u2k(hax);
          }
          else {
            if ( (u2_no == u2_cr_sing(p_hax, p_yor)) ||
                 ((u2_nul == q_hax) || (u2_nul == q_yor)) ||
                 (u2_no == u2_cr_sing(puq_hax, puq_yor)) ||
                 (u2_no == u2_cr_sing(u2h(quq_hax), u2h(quq_yor))) )
            {
              return u2_cm_error("find-fork");
            }
            switch ( u2h(quq_hax) ) {
              case u2_yes: {
                u2_noun pquq_hax = u2t(quq_hax);
                u2_noun pquq_yor = u2t(quq_yor);

                ret = u2nc
                  (
                   u2k(p_hax),
                   u2nq
                    (
                     u2_nul,
                     u2k(puq_hax),
                     u2_yes,
                     u2_cqf_fork(pquq_hax, pquq_yor)));
                break;
              }
              case u2_no: {
                u2_noun pquq_hax, qquq_hax, pquq_yor, qquq_yor;

                u2_cx_cell(u2t(quq_hax), &pquq_hax, &qquq_hax);
                u2_cx_cell(u2t(quq_yor), &pquq_yor, &qquq_yor);

                if ( u2_no == u2_cr_sing(pquq_hax, pquq_yor) ) {
                  return u2_cm_error("find-fork");
                } else {
                  ret = u2nc
                    (
                     u2k(p_hax),
                     u2nq
                      (u2_nul,
                              u2k(puq_hax),
                              u2_no,
                              u2nc
                                (u2k(pquq_hax),
                                        u2_cqb_weld
                                          (qquq_hax, qquq_yor))));
                  break;
                }
              }
            }
          }
          u2z(yor);
          u2z(hax);

          return ret;
        }
      }
      case c3__hold: p_sut = u2t(sut);
      {
        if ( (u2_yes == u2_cqdi_has(gil, sut)) ) {
          return u2nc(u2k(dep), u2_nul);
        }
        else {
          u2_noun zoc = u2_cqdi_put(gil, sut);
          u2_noun fop = u2_cqfu_repo(van, sut);
          u2_noun pro = _find_in(van, fop, dep, way, cog, zoc);

          u2z(fop);
          u2z(zoc);

          return pro;
        }
      }
    }
  }

  u2_noun
  _cqfu_find(
                        u2_noun van,
                        u2_noun sut,
                        u2_noun dep,
                        u2_noun way,
                        u2_noun cog)
  {
    return _find_in(van, sut, dep, way, cog, u2_nul);
  }

  u2_noun
  _cqfu_fino(
                        u2_noun van,
                        u2_noun sut,
                        u2_noun dep,
                        u2_noun way,
                        u2_noun cog)
  {
    return _fino_in(van, sut, dep, way, cog, u2_nul);
  }

/* boilerplate
*/
  u2_noun
  u2_cwfu_fino(
                       u2_noun cor)
  {
    u2_noun sut, dep, way, cog, van;

    if ( (u2_no == u2_cr_mean(cor, u2_cv_sam_2, &dep,
                                u2_cv_sam_6, &way,
                                u2_cv_sam_7, &cog,
                                u2_cv_con, &van,
                                0)) ||
         (u2_none == (sut = u2_cr_at(u2_cv_sam, van))) )
    {
      return u2_cm_bail(c3__fail);
    } else {
      return _cqfu_fino(van, sut, dep, way, cog);
    }
  }

  u2_noun
  u2_cqfu_fino(
                        u2_noun van,
                        u2_noun sut,
                        u2_noun dep,
                        u2_noun way,
                        u2_noun cog)
  {
    c3_m    fun_m = c3__fino;
    u2_noun pro   = u2_cz_find_4(fun_m, sut, dep, way, cog);

    if ( u2_none != pro ) {
      return pro;
    }
    else {
      pro = _cqfu_fino(van, sut, dep, way, cog);

      return u2_cz_save_4(fun_m, sut, dep, way, cog, pro);
    }
  }


/* boilerplate
*/
  u2_noun
  u2_cwfu_find(
                       u2_noun cor)
  {
    u2_noun sut, dep, way, cog, van;

    if ( (u2_no == u2_cr_mean(cor, u2_cv_sam_2, &dep,
                                u2_cv_sam_6, &way,
                                u2_cv_sam_7, &cog,
                                u2_cv_con, &van,
                                0)) ||
         (u2_none == (sut = u2_cr_at(u2_cv_sam, van))) )
    {
      return u2_cm_bail(c3__fail);
    } else {
      return _cqfu_find(van, sut, dep, way, cog);
    }
  }

  u2_noun
  u2_cqfu_find(
                        u2_noun van,
                        u2_noun sut,
                        u2_noun dep,
                        u2_noun way,
                        u2_noun cog)
  {
    c3_m    fun_m = c3__find;
    u2_noun pro   = u2_cz_find_4(fun_m, sut, dep, way, cog);

    if ( u2_none != pro ) {
      return pro;
    }
    else {
      pro = _cqfu_find(van, sut, dep, way, cog);

      return u2_cz_save_4(fun_m, sut, dep, way, cog, pro);
    }
  }
