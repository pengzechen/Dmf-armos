
#ifndef __THREAD_H__
#define __THREAD_H__

struct thread_info {
	int             cpu;
	unsigned int    flags;
	void            *pgtable;
#if 0
	vector_fn       vector_handlers[VECTOR_MAX];
	exception_fn    exception_handlers[VECTOR_MAX][EC_MAX];
#endif

	char ext[0];		/* allow unit tests to add extended info */
};

#define MIN_THREAD_SHIFT	14	/* THREAD_SIZE == 16K */

#define THREAD_SIZE		(1UL << MIN_THREAD_SHIFT)


register unsigned long current_stack_pointer asm("sp");

static inline struct thread_info * current_thread_info(void)
{
	return thread_info_sp(current_stack_pointer);
}

static inline struct thread_info *thread_info_sp(unsigned long sp)
{
	return (struct thread_info *)(sp & ~(THREAD_SIZE - 1));
}


#endif // __THREAD_H__