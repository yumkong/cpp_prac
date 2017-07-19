# each task could be done in one interval, for each interval cpu could finish one task or just be idle
# there is a non-negative cooling interval n meaning at least n intervals should be between two same 
# tasks (these intervals could either be used for doing other tasks or just be idle)
# RETURN the least number of intervals cpu needs to finish all the given tasks
class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        task_dict = dict()
        cnt = 0 # max number of the same task
        leng = len(tasks)
        for i in range(leng):
            if task_dict.has_key(tasks[i]):
                task_dict[tasks[i]] += 1
            else:
                task_dict[tasks[i]] = 1
            cnt = max(cnt, task_dict[tasks[i]])
        # the task of maximum number decides the total intervals 
        step_num = (n + 1) * (cnt - 1) # cnt - 1: not count the last appear 
        for task_name, task_num in task_dict.iteritems():
            if task_num == cnt:
                step_num += 1
        
        return max(leng, step_num)

if __name__ == '__main__':
    solu = Solution()
    print solu.leastInterval(['A','A','A','B','B','B'], 2)
