/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

namespace ECS {
  class World;

  class AFinalNode {
  protected:
    unsigned int	uniqueId_;
    World		*world_;
    bool		muted_;

  public:
    AFinalNode(void);
    // for internal purpose
    unsigned int	getUniqueId(void);
    void		setUniqueId(unsigned int id);
    void		bindWorld(World *w);
    void		unbindWorld(void);
    bool		isMuted(void) const;
    void		setMuted(bool b);
    virtual void	mute(float time = -1) = 0;
    virtual void	unmute(void) = 0;
    virtual void	remove(void) = 0;
    virtual ~AFinalNode();
  };
}
