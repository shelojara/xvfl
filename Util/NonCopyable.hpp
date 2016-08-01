#ifndef VFL_NONCOPYABLE_HPP
#define VFL_NONCOPYABLE_HPP


class NonCopyable
{
protected:
    NonCopyable() = default;
    virtual ~NonCopyable() = default;

private:
    NonCopyable(const NonCopyable &);
    NonCopyable& operator=(const NonCopyable &);
};


#endif //VFL_NONCOPYABLE_HPP
