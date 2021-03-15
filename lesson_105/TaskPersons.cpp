class TeamTasks {
public:
	const TasksInfo& GetPersonTasksInfo(const string& person) const
	{
		return Persons.at(person);
	}

	void AddNewTask(const string& person)
	{
		Persons[person][TaskStatus::NEW]++;
	}

	// Обновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
	{
		int untouched_tasks_NEW = 0;
		int temp = 0;

		if (Persons[person][TaskStatus::NEW] > task_count)
		{
			Persons[person][TaskStatus::NEW] -= task_count;
			untouched_tasks_NEW = Persons[person][TaskStatus::NEW];
			temp = task_count;
			task_count = 0;
		}
		else
		{
			task_count -= Persons[person][TaskStatus::NEW];
			temp = Persons[person][TaskStatus::NEW];
			Persons[person][TaskStatus::NEW] = 0;
		}

		int updated_tasks_IN_PROGRESS = 0;
		int untouched_tasks_IN_PROGRESS = 0;

		if (Persons[person][TaskStatus::IN_PROGRESS] > task_count)
		{
			Persons[person][TaskStatus::IN_PROGRESS] -= task_count;
			untouched_tasks_IN_PROGRESS = Persons[person][TaskStatus::IN_PROGRESS];

			updated_tasks_IN_PROGRESS = temp;
			Persons[person][TaskStatus::IN_PROGRESS] += temp;

			temp = task_count;
			task_count = 0;
		}
		else
		{
			updated_tasks_IN_PROGRESS = temp;
			task_count -= Persons[person][TaskStatus::IN_PROGRESS];

			temp = Persons[person][TaskStatus::IN_PROGRESS];
			Persons[person][TaskStatus::IN_PROGRESS] = 0;
			Persons[person][TaskStatus::IN_PROGRESS] += updated_tasks_IN_PROGRESS;
		}

		int updated_tasks_TESTING = 0;
		int untouched_tasks_TESTING = 0;

		if (Persons[person][TaskStatus::TESTING] > task_count)
		{
			Persons[person][TaskStatus::TESTING] -= task_count;
			untouched_tasks_TESTING = Persons[person][TaskStatus::TESTING];

			updated_tasks_TESTING = temp;
			Persons[person][TaskStatus::TESTING] += temp;

			temp = task_count;
			task_count = 0;
		}
		else
		{
			updated_tasks_TESTING = temp;
			task_count -= Persons[person][TaskStatus::TESTING];

			temp = Persons[person][TaskStatus::TESTING];
			Persons[person][TaskStatus::TESTING] = 0;
			Persons[person][TaskStatus::TESTING] += updated_tasks_TESTING;
		}

		int updated_tasks_DONE = 0;

		updated_tasks_DONE = temp;
		Persons[person][TaskStatus::DONE] += temp;

		TasksInfo updated_tasks;
		TasksInfo untouched_tasks;
		updated_tasks.clear();
		untouched_tasks.clear();

		if (untouched_tasks_NEW > 0)
			untouched_tasks[TaskStatus::NEW] = untouched_tasks_NEW;

		if (updated_tasks_IN_PROGRESS > 0)
			updated_tasks[TaskStatus::IN_PROGRESS] = updated_tasks_IN_PROGRESS;
		if (untouched_tasks_IN_PROGRESS > 0)
			untouched_tasks[TaskStatus::IN_PROGRESS] = untouched_tasks_IN_PROGRESS;

		if (updated_tasks_TESTING > 0)
			updated_tasks[TaskStatus::TESTING] = updated_tasks_TESTING;
		if (untouched_tasks_TESTING > 0)
			untouched_tasks[TaskStatus::TESTING] = untouched_tasks_TESTING;

		if (updated_tasks_DONE > 0)
			updated_tasks[TaskStatus::DONE] = updated_tasks_DONE;



		if (Persons[person][TaskStatus::NEW] == 0)
		{
			Persons[person].erase(TaskStatus::NEW);
		}
		if (Persons[person][TaskStatus::IN_PROGRESS] == 0)
		{
			Persons[person].erase(TaskStatus::IN_PROGRESS);
		}
		if (Persons[person][TaskStatus::TESTING] == 0)
		{
			Persons[person].erase(TaskStatus::TESTING);
		}
		if (Persons[person][TaskStatus::DONE] == 0)
		{
			Persons[person].erase(TaskStatus::DONE);
		}

		return { updated_tasks, untouched_tasks };
	}

private:
	map<string, TasksInfo> Persons;
};
